#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat img;

vector<vector<int>> newPoints;
vector<vector<int>> Colors{//Conjunto de cores detectáveis (HSVmin, HSVmax)
							{124, 24, 0, 141, 156, 255},//Roxo
							{100, 88, 82, 127, 226, 189},//Azul Claro
							{99, 94, 3, 127, 187, 167},//Azul Escuro
							{43, 104, 149, 67, 191, 255},//Verde
							{12, 139, 168, 27, 226, 255},//Laranja
							{24, 80, 123, 41, 149, 248},//Amarelo
							{0, 147, 56, 9, 255, 175} //Vinho
};
vector<Scalar> ColorValues{{255,30,255},{255,100,100},{255,10,10},{0,255,0},{0,100,255},{0,255,255},{0,0,255}};
vector<string> ColorNames{ {"Roxo"},{"Azul Claro"},{"Azul Escuro"},{"Verde"},{"Laranja"},{"Amarelo"},{"Vinho"}};

Point getContours(Mat imgDil) { //Segunda imagem é a image que será desenhada
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1, Scalar(0, 0, 0), 3);

	vector<vector<Point>> conPoly(contours.size()); //Arestas do contorno
	vector<Rect> boundRect(contours.size()); //Vetor de retângulos, irá armazenar os retângulos;
	Point centerPoint(0, 0);
	//Filtros
	for (int i = 0; i < contours.size(); i++) {
		int area = contourArea(contours[i]);
		cout << area << endl;


		if (area > 1000) {
			float peri = arcLength(contours[i], true);//pegando o perímetro  do contorno [i], e se ele é fechado ou não
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			boundRect[i] = boundingRect(conPoly[i]);
			centerPoint.x = boundRect[i].x + boundRect[i].width / 2;
			centerPoint.y = boundRect[i].y;
			//drawContours(img, conPoly, i, Scalar(255, 30, 255), 3);
			//rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(255, 0, 0), 5);
		}
	}
	return centerPoint;
}

vector<vector<int>> findColor(Mat img) {
	Mat imgHSV;
	cvtColor(img, imgHSV, COLOR_BGR2HSV); 
	
	for (int i=0; i < Colors.size(); i++) {
		Scalar lowerLimit(Colors[i][0], Colors[i][1], Colors[i][2]); //i indica a cor, neste caso
		Scalar upperLimit(Colors[i][3], Colors[i][4], Colors[i][5]);
		Mat  mask;
		inRange(imgHSV, lowerLimit, upperLimit, mask);
		//imshow(ColorNames[i], mask);
		Point centerPoint = getContours(mask);

		if (centerPoint.x != 0 && centerPoint.y != 0) {
			newPoints.push_back({ centerPoint.x , centerPoint.y , i });
		}
	}
	return newPoints;
}

void Draw(vector<vector<int>> newPoints, vector<Scalar> ColorValues) {
	for (int i = 0; i < newPoints.size(); i++) {
		circle(img, Point(newPoints[i][0], newPoints[i][1]), 10, ColorValues[newPoints[i][2]], FILLED);
	}
}

int main() {
	VideoCapture cap(0);
	

	while (1) {
		cap.read(img);

		newPoints = findColor(img);
		Draw(newPoints, ColorValues);

		imshow("Image", img);
		waitKey(1);
	}
	return 0;
}
