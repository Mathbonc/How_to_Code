#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//images//

int main() {
	string path = "Recursos/Lucas.png";
	Mat img = imread(path);

	CascadeClassifier faceCascade;
	faceCascade.load("Recursos/haarcascade_frontalface_default.xml");
	if (faceCascade.empty()) {
		cout << "Não Carregou!" << endl;
	}

	vector<Rect> faces;
	faceCascade.detectMultiScale(img, faces, 1.1, 10); //Segundo número é o número mínimo de vizinhos

	for (int i = 0; i < faces.size(); i++) {
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 0, 255), 2);
	}

	imshow("Image", img);
	waitKey(0);
	return 0;
}