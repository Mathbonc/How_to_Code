#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void getContours(Mat imgDil, Mat img) { //Segunda imagem é a image que será desenhada
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1, Scalar(0, 0, 0), 3);
	
	vector<vector<Point>> conPoly(contours.size()); //Arestas do contorno
	vector<Rect> boundRect(contours.size()); //Vetor de retângulos, irá armazenar os retângulos;
	
	//Filtros
	for (int i = 0; i < contours.size(); i++) {
		int area = contourArea(contours[i]);
		cout << area << endl;
		

		if (area > 1000) {
			float peri = arcLength(contours[i], true);//pegando o perímetro  do contorno [i], e se ele é fechado ou não
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			//drawContours(img, contours, i, Scalar(0, 0, 0), 3);
			drawContours(img, conPoly, i, Scalar(0, 255, 0), 3);
			cout << conPoly[i].size() << endl;
			boundRect[i] = boundingRect(conPoly[i]);//Achando e salvando a "hit box"
			//rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 0, 255), 2);
			int objCorner = (int) conPoly[i].size(); //Pega o número de vértices
			string objType;

			if (objCorner == 3) {
				objType = "Triangulo";
			}
			else if (objCorner == 4) {
				float aspRatio = (float) boundRect[i].width / (float) boundRect[i].height;
				if (aspRatio > 0.95 && aspRatio < 1.05) {
					objType = "Quadrado";
				}
				else {
					objType = "Retangulo";
				}
			}
			else if (objCorner > 4) {
				objType = "Circulo";
			}

			putText(img, objType, {boundRect[i].x, boundRect[i].y -5}, FONT_HERSHEY_COMPLEX, 0.75, Scalar(0, 0, 0), 2);
		}
	}
}

int main() {
	string path = "Recursos/Formas.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil;

	//Preprocessing
	cvtColor(img, imgGray, COLOR_BGR2GRAY); 
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3)); 
	dilate(imgCanny, imgDil, kernel);// Neste caso, fazemos a dilatação para tampar os "gaps" que ficam no Canny

	getContours(imgDil, img);

	imshow("Image", img);
	
	waitKey(0);
	return 0;
}
