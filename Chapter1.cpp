#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std; 
using namespace cv;

//IMPORTING IMAGE
/*
void main() {

	string path = "Resources/test.png";

	//Mat is a datatype to handle images
	Mat img = imread(path);
	imshow("image", img);
	waitKey(0);

}
*/


//IMPORTING VIDEO
/*
void main() {

	string path = "Resources/test_video.mp4";
	VideoCapture cap(path);
	Mat img;
	while (true) {
		//read image from object cap
		cap.read(img);
		imshow("Image", img);
		waitKey(20);

	}
}

*/

//CAPTURING VIDEO FROM WEBCAM
void main() {

	//capturing video from webcamera
	VideoCapture cap(0);
	Mat img;
	while (true) {

		cap.read(img);
		imshow("Image", img);
		waitKey(1);

	}
}