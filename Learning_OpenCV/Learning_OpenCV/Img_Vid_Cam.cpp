#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//images//

//int main() {
//	string path = "Recursos/Keqing.png";
//	Mat img = imread(path);
//	imshow("Image", img);
//	waitKey(0);
//	return 0;
//}

//videos//

int main() {

	string path = "Recursos/VideoTeste.mp4";
	VideoCapture cap(path); //Para ligar a webcam, usamos apenas o ID dela "cap(0)", 0 para apenas uma câmera
	Mat img;

	while (1) {
		cap.read(img);
		imshow("Image", img);

		waitKey(200); //Delay de 1ms
	}
	return 0;
}