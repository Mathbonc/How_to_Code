#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	string path = "Recursos/Keqing.png";
	Mat img = imread(path);
	Mat imgResize, imgScaled, imgCrop;

	cout << img.size() << endl;

	//RESIZE//
	/*
	resize(img, imgResize, Size(1024, 1229));
	resize(img, imgScaled, Size(), 0.5 ,0.5);

	imshow("Image", img);
	imshow("Image Bigger", imgResize);
	imshow("Image Scaled", imgScaled);
	*/
	//CROP//
	Rect roi(330, 512, 300, 250);
	imgCrop = img(roi);
	imshow("Image Crop", imgCrop);


	waitKey(0);
	return 0;
}
