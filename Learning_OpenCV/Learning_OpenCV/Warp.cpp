#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	string path = "Recursos/Cartas.png";
	Mat img = imread(path), WarpedImg,matrix;
	float width = 250, height = 350;//Tamanho da carta em si
	//Coordenadas (367,96)(537,132)(278,273)(470,318)

	Point2f src[4] = { {367,96},{537,132},{278,273},{470,318} };
	Point2f Dest[4] = { {0.0f,0.0f},{width,0.0f},{0.0f,height},{width,height} };

	matrix = getPerspectiveTransform(src, Dest);
	warpPerspective(img, WarpedImg, matrix, Point(width, height));

	for (int i = 0; i < 4; i++) {
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED); //"DEBUG", deve ser feito depois do warp,pois se não os círculos irão aparecer
	}

	imshow("Image", img);
	imshow("Image Warp", WarpedImg);
	waitKey(0);
	return 0;
}
