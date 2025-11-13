
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include <cmath>
#include <opencv2/core.hpp>

using namespace std;
vector<double> cRef(3);//x y z center
vector<double> cTxt(3);//x y z center
vector<vector<double>> obRef;//obringnal pos
vector<vector<double>> decenRef;//decentralize pos
vector<vector<double>> obTxt;//obringnal pos
vector<vector<double>> decenTxt;//decentralize pos
vector<char>txtChar;
vector<char>refChar;
void center(ifstream& fin,vector<double>& cen,vector<vector<double>> &ob,vector<char>& word) {
	double sumX = 0, sumY = 0, sumZ = 0;
	string input;
	double tmp1, tmp2, tmp3;
	char no;
	while (fin>>tmp1>>tmp2>>tmp3>>no)
	{
		vector<double>tmpVt(3);
		tmpVt[0] = tmp1;
		tmpVt[1] = tmp2;
		tmpVt[2] = tmp3;
		ob.push_back(tmpVt);
		word.push_back(no);
		if(ob.size()<=12){
			sumX += tmp1;
			sumY += tmp2;
			sumZ += tmp3;
		}

	}
	cen[0] = static_cast<double>(sumX / 12);
	cen[1] = static_cast<double>(sumY / 12);
	cen[2] = static_cast<double>(sumZ / 12);
}

void decentralize(const vector<vector<double>>& ob, const vector<double>& center,vector<vector<double>>& decen) {
	decen.clear();
	for (int i = 0;i < 12;i++) {
		vector<double> tmpDecen(3); 
        tmpDecen[0] = ob[i][0] - center[0];
        tmpDecen[1] = ob[i][1] - center[1];
        tmpDecen[2] = ob[i][2] - center[2];
        
        
        decen.push_back(tmpDecen);
	}
}
cv::Mat conMatrix(){
    cv::Mat H_mat = cv::Mat::zeros(3, 3, CV_64F);
    for(int i=0;i<12;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                H_mat.at<double>(j, k) += decenTxt[i][j] * decenRef[i][k];
            }
        }
    }
    return H_mat;
}

int main(int argc, char* argv[])
{
	ifstream fin1,fin2;
	fin1.open(argv[1]);
	fin2.open(argv[2]);
	//fin.open("in_1.txt");
	//string input;
	int ind = 0;
	center(fin1, cTxt,obTxt,txtChar);
	fin1.close();
	center(fin2, cRef,obRef,refChar);
	fin2.close();
	decentralize(obTxt, cTxt, decenTxt);
	decentralize(obRef, cRef, decenRef);
    cv::Mat H_matrix = conMatrix();
	cv::SVD svd(H_matrix); //SVD分解
	cv::Mat U = svd.u;  // U 矩陣 (3x3)
	cv::Mat V = svd.vt.t(); // V 矩陣 (3x3)，注意 svd.vt 是 V 的轉置
	
	//計算 R_initial = V * U^T
	cv::Mat R_initial = V * U.t(); // U.t() 是 U 的轉置
	
	//創建 S 矩陣並檢查行列式
	cv::Mat S = cv::Mat::eye(3, 3, CV_64F);

	// 如果行列式小於 0 (即 -1)，則將 S 矩陣的右下角元素設為 -1 進行修正
	if (cv::determinant(R_initial) < 0) {
    	S.at<double>(2, 2) = -1.0; 
	}

	//計算最終的最佳旋轉矩陣 R = V * S * U^T
	cv::Mat R = V * S * U.t();

	//將質心向量 (cRef, cTxt) 轉換為 3x1 的 Mat
	cv::Mat C_ref_mat = (cv::Mat_<double>(3, 1) << cRef[0], cRef[1], cRef[2]);
	cv::Mat C_case_mat = (cv::Mat_<double>(3, 1) << cTxt[0], cTxt[1], cTxt[2]);	

	//計算 T 矩陣 (3x1)
	cv::Mat T_mat = C_ref_mat - R * C_case_mat;


	for (size_t i = 0; i < obTxt.size(); ++i) {
    	// 2. 取得原始原子座標 P_all (3x1 Mat)
    	cv::Mat P_all = (cv::Mat_<double>(3, 1) << obTxt[i][0], obTxt[i][1], obTxt[i][2]);
    
    	// 3. 執行變換: P_out = R * P_all + T
    	cv::Mat P_out = R * P_all + T_mat;

		cout<<P_out.at<double>(0,0)<<" ";
		cout<<P_out.at<double>(1,0)<<" ";
		cout<<P_out.at<double>(2,0)<<" ";
		cout<<txtChar[i]<<endl;
	}
}