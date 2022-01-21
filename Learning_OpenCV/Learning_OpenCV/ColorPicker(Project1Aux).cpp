#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	VideoCapture cam(0);
	Mat img,imgHSV, mask;
	int hmin = 0, smin = 0, vmin = 0;
	int hmax = 0, smax = 0, vmax = 0;

	namedWindow("Track Bars", (640, 320));
	createTrackbar("Hue Min", "Track Bars", &hmin, 179); //Range do HUE é 0-180
	createTrackbar("Hue Max", "Track Bars", &hmax, 179);
	createTrackbar("Sat Min", "Track Bars", &smin, 255);
	createTrackbar("Sat Max", "Track Bars", &smax, 255);
	createTrackbar("Val Min", "Track Bars", &vmin, 255);
	createTrackbar("Val Max", "Track Bars", &vmax, 255);

	while (1) {
		cam.read(img);

		cvtColor(img, imgHSV, COLOR_BGR2HSV);

		Scalar lowerLimit(hmin, smin, vmin), upperLimit(hmax, smax, vmax);
		inRange(imgHSV, lowerLimit, upperLimit, mask);

		cout << hmin << ", " << smin << ", " << vmin << ", ";
		cout << hmax << ", " << smax << ", " << vmax << endl;
		
		imshow("Image Mask", mask);
		imshow("Image", img);
		waitKey(1);
	}
	return 0;
}
