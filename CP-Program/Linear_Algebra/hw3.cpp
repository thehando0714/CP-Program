#include <iostream>
#include <vector>
#include <algorithm>
//#include <opencv2/opencv.hpp> 
#include <fstream>
/**/#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp> 
#include <opencv2/highgui.hpp>   
using namespace std;
using namespace cv;
bool cmp(const vector<int>& a,const vector<int>& b){
    if(a[0]!=b[0])return a[0]<b[0];
    if(a[1]!=b[1])return a[1]<b[1];
    return false;
}
int main(int argc,char* argv[] ){//
    ifstream fin; 
    fin.open(argv[1]);
    //fin.open("public1.jpg");
    Mat img=imread(argv[1],IMREAD_COLOR);//read image in color
    //Mat img=imread("public1.jpg",IMREAD_COLOR);

    /*if (img.empty()) {
        cout << "讀取失敗！程式找不到 public1.jpg" << endl;
        cout << "請確認圖片路徑是否正確。" << endl;
        return -1;
    }   
    cout << "讀取成功！圖片大小: " << img.size() << endl; // 讀到了就印一下大小
    */
    GaussianBlur(img, img, Size(5, 5), 0);

    Mat hsv_img;
    cvtColor(img,hsv_img,COLOR_BGR2HSV);//source destination howto
    
    Mat yellowMask;
    inRange(hsv_img,Scalar(20,70,70),Scalar(30,255,255),yellowMask);//for yellow h low s low v low ,h up s up v up
    Mat blueMask;
    inRange(hsv_img,Scalar(100,80,70),Scalar(125,255,255),blueMask);//for blue h low s low v low ,h up s up v up ignore too light blue
    Mat redMask1,redMask2,trueRedMask;
    inRange(hsv_img,Scalar(0,70,70),Scalar(10,255,255),redMask1);
    inRange(hsv_img,Scalar(170,70,70),Scalar(180,255,255),redMask2);
    bitwise_or(redMask1,redMask2,trueRedMask);

    Mat core=getStructuringElement(MORPH_RECT,Size(5,5));//like a 5*5 brush
    morphologyEx(trueRedMask,trueRedMask,MORPH_CLOSE,core);
    morphologyEx(yellowMask,yellowMask,MORPH_OPEN,core);//erase background noise
    morphologyEx(blueMask,blueMask,MORPH_OPEN,core);
    //morphologyEx(trueRedMask,trueRedMask,MORPH_OPEN,core);
    //fill the blank
    morphologyEx(blueMask,blueMask,MORPH_CLOSE,core);
    morphologyEx(yellowMask,yellowMask,MORPH_CLOSE,core);
    //morphologyEx(trueRedMask, trueRedMask, MORPH_OPEN, core);

/**/
    
    //point have .x .y
    vector<vector<Point>>yellowShape,blueShape,redShape;//a lot of shape
    //vec4i have val[4]
    vector<Vec4i>yellowHierarchy,blueHierarchy,redHierarchy;//

    //find Contours
    //RETR_EXTERNAL mean only find outer shap
    //CHAIN_APPROX_SIMPLE mean save less point
    findContours(yellowMask,yellowShape,yellowHierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);//(input,out,output,mode,method)
    findContours(blueMask,blueShape,blueHierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
    findContours(trueRedMask,redShape,redHierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);

    vector<vector<int>>detectPosition;//x1,y1,x2,y2

    //filter
    for(int i=0;i<yellowShape.size();i++){
        double area=contourArea(yellowShape[i]);
        if(area<600||area>20000){
            continue;
        }
        //get bounding rect
        Rect rect=boundingRect(yellowShape[i]);

        double ratio = (double)rect.width / rect.height;
        if (ratio < 0.6 || ratio > 1.6) { 
            continue; 
        }
        vector<Point> approx;
        approxPolyDP(yellowShape[i], approx, 0.04 * arcLength(yellowShape[i], true), true);
        if (approx.size() < 3 || approx.size() > 15) {
            continue;
        }
        vector<int>tmp;
        tmp.push_back(rect.x);
        tmp.push_back(rect.y);
        tmp.push_back(rect.x+rect.width);
        tmp.push_back(rect.y+rect.height);
        detectPosition.push_back(tmp);
    }
    for(int i=0;i<blueShape.size();i++){
        double area=contourArea(blueShape[i]);
        if(area<600||area>20000){
            continue;;
        }
        //get bounding rect
        Rect rect=boundingRect(blueShape[i]);
        double ratio = (double)rect.width / rect.height;
        if (ratio < 0.6 || ratio > 1.6) { 
            continue; 
        }

        vector<Point> approx;
        approxPolyDP(blueShape[i], approx, 0.04 * arcLength(blueShape[i], true), true);
        if (approx.size() < 3 || approx.size() > 15) {
            continue;
        }

        vector<int>tmp;
        tmp.push_back(rect.x);
        tmp.push_back(rect.y);
        tmp.push_back(rect.x+rect.width);
        tmp.push_back(rect.y+rect.height);
        detectPosition.push_back(tmp);
    }
    for(int i=0;i<redShape.size();i++){
        double area=contourArea(redShape[i]);
        if(area<600||area>20000){
            continue;;
        }
        //get bounding rect
        Rect rect=boundingRect(redShape[i]);
        double ratio = (double)rect.width / rect.height;
        if (ratio < 0.6 || ratio > 1.6) { 
            continue; 
        }

        vector<Point> approx;
        approxPolyDP(redShape[i], approx, 0.04 * arcLength(redShape[i], true), true);
        if (approx.size() < 3 || approx.size() > 15) {
            continue;
        }

        vector<int>tmp;
        tmp.push_back(rect.x);
        tmp.push_back(rect.y);
        tmp.push_back(rect.x+rect.width);
        tmp.push_back(rect.y+rect.height);
        detectPosition.push_back(tmp);
    }
    sort(detectPosition.begin(),detectPosition.end(),cmp);
    for(int i=0;i<detectPosition.size();i++){
        cout<<detectPosition[i][0]<<" "<<detectPosition[i][1]<<" "<<detectPosition[i][2]<<" "<<detectPosition[i][3]<<"\n";
    }
}