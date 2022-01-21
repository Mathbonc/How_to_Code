#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3)); 
Mat imgGray,imgBlur,imgDil,imgCanny;

Mat preProcessing(Mat img){

    cvtColor(img, imgGray, COLOR_BGR2GRAY); 
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 70);
	dilate(imgCanny, imgDil, kernel);

    return imgDil;
}

vector<Point> getContours(Mat img) {
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	vector<vector<Point>> conPoly(contours.size()); 
	vector<Rect> boundRect(contours.size()); 
	
	vector<Point> biggest;
	for (int i = 0; i < contours.size(); i++) {
		int area = contourArea(contours[i]), maxArea=0;

		if (area > 1000) {
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			//drawContours(img, contours, i, Scalar(0, 0, 0), 3);

			if(area > maxArea && conPoly[i].size()==4){
			    drawContours(img, conPoly, i, Scalar(0, 0, 255), 2);
                biggest = {conPoly[i][0],conPoly[i][1],conPoly[i][2],conPoly[i][3]};
                maxArea = area;
            }
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 0, 255), 2);
		}
	}
    return biggest;
}

void drawPoints(Mat img, vector<Point> points){
    for(int i = 0; i<points.size(); i++){
        circle(img, points[i], 10, Scalar(0,0,255), FILLED);
    }
}

vector<Point> sortingPoints(vector<Point> points){
    vector<Point> newPoints;
    vector<int> sumPoints, subPoints;
    int index;
    for(int i=0; i<4; i++){
        sumPoints.push_back(points[i].x + points[i].y);
        subPoints.push_back(points[i].x - points[i].y);
    }

    //Devolve o index min_element(sumPoints.begin(), sumPoints.end()) - sumPoints.begin()
    newPoints.push_back(points[min_element(sumPoints.begin(), sumPoints.end()) - sumPoints.begin()]); 
    newPoints.push_back(points[max_element(subPoints.begin(), subPoints.end()) - subPoints.begin()]);
    newPoints.push_back(points[min_element(subPoints.begin(), subPoints.end()) - subPoints.begin()]); 
    newPoints.push_back(points[max_element(sumPoints.begin(), sumPoints.end()) - sumPoints.begin()]);

    return newPoints;
}

Mat getWarp(Mat img, vector<Point> points, int w, int h){
    Mat matrix,warpedImg;
    Point2f src[4] = { points[0], points[1], points[2], points[3] };
	Point2f Dest[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	matrix = getPerspectiveTransform(src, Dest);
	warpPerspective(img, warpedImg, matrix, Point(w, h));

    return warpedImg;
}

int main() {
	VideoCapture cam(0);
    Mat img,imgThreshH, imgWarp;
    vector<Point> initialPoints, finalPoints;
    float w = 420, h = 596; //Papel A4
    Rect roi(5,5, w-10, h-10);

    while(1){
        cam.read(img);
        imgThreshH = preProcessing(img);
        initialPoints = getContours(imgThreshH);
        finalPoints = sortingPoints(initialPoints);
        drawPoints(img,finalPoints);
        imgWarp = getWarp(img, finalPoints, w, h);

        imgWarp = imgWarp(roi);

        imshow("image", img);
        imshow("imgTresh", imgThreshH);
        imshow("Warped Image", imgWarp);
	    waitKey(1);
    }
	return 0;
}