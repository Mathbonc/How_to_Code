#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	//Imagem Vazia
	Mat img(512, 512, CV_8UC3, Scalar(255,255,255));//8 bits, Unsigned, 3 Channels (BGR)// Scalar define a cor (B,G,R)
	circle(img, Point(256, 256), 155, Scalar(255, 215, 0), FILLED);//Point = centro // ÚLTIMO PARÂMETRO É A GROSSURA
	rectangle(img, Point(130, 226), Point(382, 286),Scalar(255,255,255),FILLED);//Primeiro Ponto, Segundo Ponto, Cor, Grossura
	line(img, Point(130,296),Point(382,296),Scalar(255,255,255), 2);
	putText(img, "Matheus Bonxai", Point(157, 264), FONT_HERSHEY_COMPLEX, 0.75, Scalar(255, 215, 0), 2);
	imshow("Image", img);
	
	waitKey(0);
	return 0;
}
