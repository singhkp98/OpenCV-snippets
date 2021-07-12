#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/********************** DRAW SHAPES AND TEXT ***************************/

void main() {

	//create an image from scratch with size 512x512 8bit and purple color defined with Scalar
	Mat img(512, 512, CV_8UC3, Scalar(255,0,255));

	//draw circle with (input img, Center point, radius, color, thikness)
	circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED);

	//draw rectangle
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED);

	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);

	putText(img, "Testo di Prova", Point(137, 262), FONT_HERSHEY_DUPLEX, 0.75, Scalar(0, 69, 255), 2);

	imshow("Images", img); 


	waitKey(0);

}
