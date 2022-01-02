#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	string path = "Recursos/Yae.png";
	Mat img = imread(path);
	Mat imgHSV,mask;
	int hmin=0, smin=0, vmin=0;
	int hmax=0, smax=0, vmax=0;

	cvtColor(img, imgHSV, COLOR_BGR2HSV); //Convertendo para HSV

	namedWindow("Track Bars", (640, 320));
	createTrackbar("Hue Min", "Track Bars", &hmin, 179); //Range do HUE é 0-180
	createTrackbar("Hue Max", "Track Bars", &hmax, 179);
	createTrackbar("Sat Min", "Track Bars", &smin, 255);
	createTrackbar("Sat Max", "Track Bars", &smax, 255);
	createTrackbar("Val Min", "Track Bars", &vmin, 255);
	createTrackbar("Val Max", "Track Bars", &vmax, 255);

	imshow("Image", img);
	imshow("Image HSV", imgHSV);
	while (1) {

		Scalar lowerLimit(hmin, smin, vmin), upperLimit(hmax, smax, vmax);//Hue, Saturação e Valor 
		inRange(imgHSV, lowerLimit, upperLimit, mask);// Cria a máscara de acordo com aquela cor

		imshow("Image Mask", mask);


		waitKey(1);
	}
	return 0;
}
