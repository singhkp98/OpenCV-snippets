#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//SHAPE DETECTING 

Mat imgGray, imgBlur, imgCanny, imgDil;

void getContours(Mat imgDil, Mat img) {
	
	/* The variable contours is composed by a vector containing other vectors which are containing
	Points (Point) { {Point(20,30),Point(50,60)}, {Point(10,20),Point(20,30)}, {...} } */
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy; //not used

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_NONE);

	/* draw purpule contours around images(moved into for loop, read comment to understand why)
	drawContours(img, contours, -1, Scalar(255, 0, 255), 10); */

	/* it is like contours vector, will not have all the points but only the curves points
	rectangle 4 points, triangle 3 points, circle >6 points etc.
	We fix the size (the size of this array cannot exceed the size of contours array */ 
	vector<vector<Point>> conPoly(contours.size());

	/* vector variable to store the bounding rectangles found with boundingRect function */
	vector<Rect> boundRect(contours.size());

	string objectType;

	//find area for every shape
	for (int i = 0; i < contours.size(); i++) {
		
		int area = contourArea(contours[i]);
		/* print area of every shape.If area is less then 1000 the shape is useless
		so I will not draw a contour around it. This process help me to get only 
		the shapes that I need. */
		cout << area << endl;
		
		if (area > 1000) {
			
			/* find the perimeter passing to arcLength the contours of each shape
			true -> because de shape is closed */
			float peri = arcLength(contours[i], true);

			/* find the numbers of curves that a polygon has.
			So we can say that if a polygon has 4 curves is a rectangle, 3 a triangle, a lot then circle.
			Pass the i th element of contours and store the value in a new array 'conPoly' which will be the output.
			then pass a random number multiplied by the perimeter and true value for closed shapes. */
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

			//print the numbers of curves founded
			cout << conPoly[i].size() << endl;

			//found the bounding rectangle around the shape
			boundRect[i] = boundingRect(conPoly[i]);

			int objCor = (int)conPoly[i].size();

			if (objCor == 3) {
				objectType = "Tri";
			}
			if (objCor == 4) {
				
				float aspRatio = (float)boundRect[i].width / boundRect[i].height;
				if (aspRatio > 0.95 && aspRatio < 1.05) {
					objectType = "Square";
				}
				else {
					objectType = "Rect";
				}
				
			}
			if (objCor > 4) {
				objectType = "Circle";
			}
			
			//drawContours(img, contours, -1, Scalar(255, 0, 255), 10);

			//I can draw directly the curves instead of drawing the whole contours
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 10);

			//draw the bounding rectangle around the shape 
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);

			putText(img, objectType, { boundRect[i].x, boundRect[i].y - 5 }, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 2);
		}
	}
}

void main() {

	string path = "Resources/shapes.png";
	Mat img = imread(path);

	//preprocessing of the image
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(7, 7), 5, 0);
	Canny(imgBlur, imgCanny, 50, 150);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	dilate(imgCanny, imgDil, kernel);

	getContours(imgDil, img);

	imshow("Image", img);
	/*imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dil", imgDil);*/

	waitKey(0);

}
