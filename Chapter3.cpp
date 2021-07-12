#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/********************** RESIZE AND CROP ***************************/

void main() {

	string path = "Resources/test.png";

	Mat img = imread(path);
	Mat imgResize, imgCrop;

	cout << img.size() << endl; 

	//resize the image
	resize(img, imgResize, Size(640, 480));
	
	//this will scale instead of resizing in pixel
	resize(img, imgResize, Size(),0.5,0.5);

	//define the region of interest which I wanto to crop to (x,y,width,height)
	Rect roi(100, 100, 300, 250);
	//crop the image by passing the region of interest
	imgCrop = img(roi);

	imshow("Image", img);
	imshow("Image Resize", imgResize);
	imshow("Image Crop", imgCrop);


	waitKey(0);

}
