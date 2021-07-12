#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/********************** BASIC FUNCTIONS ***************************/

void main() {

	string path = "Resources/test.png";

	//Mat is a datatype to handle images
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

	//convert img into new imgGray -> BGR2GRAY (N.B is BGR not RGB)
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	//blur img (input image, output image, function parameters)
	GaussianBlur(imgGray, imgBlur, Size(7, 7), 5, 0);
	//edge detection with canny image (for edge detection you should pass a blurred image as input)
	Canny(imgBlur, imgCanny, 50, 150);

	//create a kernel to use with dilation (if increase size it will dilate more)
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	//perform a dilation on imgCanny (will dilatate the edges and increase the thickness)
	dilate(imgCanny, imgDil, kernel);
	//perform an erosion on previous dilatated image (will decrease the thickness)
	erode(imgDil, imgErode, kernel); 

	imshow("Image", img);
	imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dilation", imgDil);
	imshow("Image Dilation", imgDil);
	imshow("Image Erode", imgErode);

	waitKey(0);

}
