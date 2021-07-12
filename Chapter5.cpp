#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/********************** WARP IMAGES ***************************/

float w = 250, h = 350; 
Mat matrix, imgWarp; 

void main() {

	string path = "Resources/cards.jpg";
	Mat img = imread(path);

	//defining the 4 points (floating values) of my image corrisponding to the area I want to warp. 
	Point2f src[4] = { {529,142},{771,190},{405,395},{674,457} };

	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	matrix = getPerspectiveTransform(src, dst); 

	warpPerspective(img, imgWarp, matrix, Point(w, h));

	//design a mini circle around the 4 points selected to warp the image
	for (int i = 0; i < 4; i++) {
		//select the points from the array src[i]
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
	}

	imshow("Image", img);
	imshow("Image warp", imgWarp);

	waitKey(0);

}
