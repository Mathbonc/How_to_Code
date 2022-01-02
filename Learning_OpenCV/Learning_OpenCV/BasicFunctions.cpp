#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	string path = "Recursos/Keqing.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur,imgCanny, imgDil, imgErode;

	cvtColor(img, imgGray, COLOR_BGR2GRAY); //"Convert Color"
	GaussianBlur(imgGray, imgBlur, Size(9,9),5,0);//(É possível aperta na função usando ctrl p/ acessar a documentação dela) O KERNEL PRECISA SER UMA MATRIZ IMPAR
	Canny(imgBlur,imgCanny,10,30);//Quando usamos um "Edge Detector", geralmente fazemos isso com uma imagem borrada (blur)

	Mat kernel = getStructuringElement(MORPH_RECT, Size(5,5)); //Cria um Kernal que pode ser usado com "dilate". Quanto maior, mais dilata.
	dilate(imgCanny, imgDil, kernel);
	erode(imgDil, imgErode, kernel);

	imshow("Image", img);
	imshow("Imgage Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dilate", imgDil);
	imshow("Image Erode", imgErode);

	waitKey(0);
	return 0;
}
