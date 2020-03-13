// Identified.cpp
#include "stdafx.h"
#include "Identified.h"
#include "Tools.h"
#include "ListOfDriver.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
void identified() {

	string bienSo;

	bool blnKNNTrainingSuccessful = loadKNNDataAndTrainKNN();           // attempt KNN training

	if (blnKNNTrainingSuccessful == false) {                            // if KNN training was not successful
																		// show error message
		cout << endl << endl << "Qua trinh dao tao Machine Learning khong thanh cong." << endl << endl;
	}

	cv::Mat imgOriginalScene;           // input image

	cin.ignore();
	cout << "Nhap duong dan toi anh can nhan dien: ";
	string imgName;
	getline(cin, imgName);

	PlaySound(TEXT("Identified.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

	imgOriginalScene = cv::imread(imgName);         // open image

	cout << "\n\tDang nhan dien hinh anh, vui long cho . . . " << endl;

	if (imgOriginalScene.empty()) {                             // if unable to open image
		cout << "Loi: Khong the doc duoc anh nay\n\n";     // show error message on command line
														   //    _getch();                                              // and exit program
	}
	else
	{


		vector<PossiblePlate> vectorOfPossiblePlates = detectPlatesInScene(imgOriginalScene);          // detect plates

		vectorOfPossiblePlates = detectCharsInPlates(vectorOfPossiblePlates);                               // detect chars in plates

																											//	Hoan Glad does not want to show
																											//  cv::imshow("imgOriginalScene", imgOriginalScene);           // show scene image

		if (vectorOfPossiblePlates.empty()) {                                               // if no plates were found
			cout << endl << "Khong phat hien duoc bien so" << endl;       // inform user no plates were found
		}
		else {                                                                            // else
																						  // if we get in here vector of possible plates has at leat one plate
																						  // sort the vector of possible plates in DESCENDING order (most number of chars to least number of chars)

			sort(vectorOfPossiblePlates.begin(), vectorOfPossiblePlates.end(), PossiblePlate::sortDescendingByNumberOfChars);

			// suppose the plate with the most recognized chars (the first plate in sorted by string length descending order) is the actual plate
			PossiblePlate licPlate = vectorOfPossiblePlates.front();

			//	Hoan Glad does not want to show
			//       cv::imshow("imgPlate", licPlate.imgPlate);            // show crop of plate and threshold of plate
			//       cv::imshow("imgThresh", licPlate.imgThresh);

			if (licPlate.strChars.length() == 0) {                                                      // if no chars were found in the plate
				cout << endl << "Khong tim thay ki tu nao" << endl << endl;      // show message                                                                           // and exit program
			}

			else
			{
				drawRedRectangleAroundPlate(imgOriginalScene, licPlate);                // draw red rectangle around plate

				bienSo = licPlate.strChars;

				cout << endl << "Bien so doc duoc tu anh: " << licPlate.strChars << endl;     // write license plate text to std out

				writeLicensePlateCharsOnImage(imgOriginalScene, licPlate);              // write license plate text on the image

																						//	Hoan Glad (does not) want to show
																						//  cv::imshow("imgOriginalScene", imgOriginalScene);                       // re-show scene image

				cv::imwrite("imgOriginalScene.png", imgOriginalScene);                  // write image out to file

			}

		}
	}
	Tools a;
	ListOfDriver ds;
	ListOfVehicle list;
	string ID;
	ifstream f;
	bool exist = false;
	long long lai = 0, tongLai = 0;
	string id = "", tenTX = "", idTX = "", tenXe = "";
	f.open("PhuongTien.data");
	do {
		f >> ID >> tenXe >> idTX >> lai;
		string idTmp = ID;
		idTmp.erase(0, 3);
		if (idTmp == bienSo) {
			exist = true;
			break;
		}
	} while (!f.eof());
	f.close();
	Sleep(500);
	PlaySound(TEXT("Successed.wav"), NULL, SND_FILENAME | SND_SYNC);
	Sleep(1000);
	PlaySound(TEXT("Main.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	/*cv::Mat anhDaXuLi;
	anhDaXuLi = cv::imread("imgOriginalScene.png");
	cv::imshow("Result", anhDaXuLi);*/
	if (exist) {
		cout << "Thong tin xe:\n\tID xe: " << ID << "\n\tTen Xe: " << a.convertToShow(tenXe) << "\n\tID Tai Xe: " << idTX << "\n\tDoanh Thu: " << lai << endl;
		ds.findVehicle(ID);
		char c = 'K';
		do {
			cout << "Ban co muon cap nhat du lieu khong? (C,K)\n\tChon: ";
			cin >> c;
			c = toupper(c);
			if (c == 'C')
			{
				list.updateInfo(ID);
				break;
			}
		} while (c != 'K');
	}
	else {
		cout << "Khong ton tai bien so tren he thong hoac he thong khong nhan dien duoc." << endl;
		char c = 'K';
		do {
			cout << "Ban co muon cap nhat du lieu khong? (C,K)\n\tChon: ";
			cin >> c;
			c = toupper(c);
			if (c == 'C')
			{
				list.inputListVehicle();
				break;
			}
		} while (c != 'K');
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void drawRedRectangleAroundPlate(cv::Mat &imgOriginalScene, PossiblePlate &licPlate) {
	cv::Point2f p2fRectPoints[4];

	licPlate.rrLocationOfPlateInScene.points(p2fRectPoints);            // get 4 vertices of rotated rect

	for (int i = 0; i < 4; i++) {                                       // draw 4 red lines
		cv::line(imgOriginalScene, p2fRectPoints[i], p2fRectPoints[(i + 1) % 4], SCALAR_RED, 2);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void writeLicensePlateCharsOnImage(cv::Mat &imgOriginalScene, PossiblePlate &licPlate) {
	cv::Point ptCenterOfTextArea;                   // this will be the center of the area the text will be written to
	cv::Point ptLowerLeftTextOrigin;                // this will be the bottom left of the area that the text will be written to

	int intFontFace = CV_FONT_HERSHEY_SIMPLEX;                              // choose a plain jane font
	double dblFontScale = (double)licPlate.imgPlate.rows / 30.0;            // base font scale on height of plate area
	int intFontThickness = (int)round(dblFontScale * 1.5);             // base font thickness on font scale
	int intBaseline = 0;

	cv::Size textSize = cv::getTextSize(licPlate.strChars, intFontFace, dblFontScale, intFontThickness, &intBaseline);      // call getTextSize

	ptCenterOfTextArea.x = (int)licPlate.rrLocationOfPlateInScene.center.x;         // the horizontal location of the text area is the same as the plate

	if (licPlate.rrLocationOfPlateInScene.center.y < (imgOriginalScene.rows * 0.75)) {      // if the license plate is in the upper 3/4 of the image
																							// write the chars in below the plate
		ptCenterOfTextArea.y = (int)round(licPlate.rrLocationOfPlateInScene.center.y) + (int)round((double)licPlate.imgPlate.rows * 1.6);
	}
	else {                                                                                // else if the license plate is in the lower 1/4 of the image
																						  // write the chars in above the plate
		ptCenterOfTextArea.y = (int)round(licPlate.rrLocationOfPlateInScene.center.y) - (int)round((double)licPlate.imgPlate.rows * 1.6);
	}

	ptLowerLeftTextOrigin.x = (int)(ptCenterOfTextArea.x - (textSize.width / 2));           // calculate the lower left origin of the text area
	ptLowerLeftTextOrigin.y = (int)(ptCenterOfTextArea.y + (textSize.height / 2));          // based on the text area center, width, and height

																							// write the text on the image
	cv::putText(imgOriginalScene, licPlate.strChars, ptLowerLeftTextOrigin, intFontFace, dblFontScale, SCALAR_YELLOW, intFontThickness);
}


