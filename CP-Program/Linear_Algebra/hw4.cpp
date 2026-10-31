#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
   
    Mat src = imread(argv[1], IMREAD_GRAYSCALE);

    Mat binImg;
    threshold(src, binImg, 200, 255, THRESH_BINARY);

    vector<vector<Point>> contours;
    findContours(binImg, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    

    if (contours.size() == 0) {
        imwrite(argv[2], src);
        return 0;
    }

    int max_idx = -1;
    double max_area = 0;
    
    for (int i = 0; i < contours.size(); i++) {
        double a = contourArea(contours[i]);
        if (a > max_area) {
            max_area = a;
            max_idx = i;
        }
    }

    
    Mat mask = Mat::zeros(src.size(), CV_8UC1);
    drawContours(mask, contours, max_idx, Scalar(255), FILLED);

    Mat img2;
    src.copyTo(img2, mask);
    
    Mat result = img2.clone();


    if (max_idx != -1 && contours[max_idx].size() >= 5) {
        RotatedRect rect = fitEllipse(contours[max_idx]);
        
        float ang = rect.angle;
        float rotateVal = 0;
        if (rect.size.width < rect.size.height) {
            rotateVal = ang;
        } else {
            rotateVal = ang - 90;
        }

        
        Mat M = getRotationMatrix2D(rect.center, rotateVal, 1.0);
        warpAffine(img2, result, M, src.size(), INTER_LINEAR, BORDER_CONSTANT, Scalar(0));
    }
    imwrite(argv[2], result);

    return 0;
}