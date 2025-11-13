
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include <cmath>
using namespace std;

int m = 0, n = 0,t=0;
vector<vector<double>>matrix1, matrix2;
void solve() {
	int rankA = 0, rankB = 0;

	//matrix1 start
	for (int ind = 0;ind < min(m,n);ind++) {
		int bigRow = ind;
		for (int i = ind + 1; i < matrix1.size(); i++) {
			if (fabs(matrix1[i][ind]) > fabs(matrix1[bigRow][ind])) {
				bigRow = i;
			}
		}
		if (bigRow != ind) {
			for (int k = 0; k < matrix1[0].size(); k++) {
				double temp = matrix1[ind][k];
				matrix1[ind][k] = matrix1[bigRow][k];
				matrix1[bigRow][k] = temp;
			}
		}
		if (fabs(matrix1[ind][ind]) < 1e-10) {
			continue;
		}
		for (int i = 0; i < matrix1.size(); i++) {
			if (i <= ind) {
				continue;
			}
			double multi = -(matrix1[i][ind] / matrix1[ind][ind]);
			for (int k = ind; k < matrix1[0].size(); k++) {
				matrix1[i][k] += (multi * matrix1[ind][k]);
			}
		}
	}

	for (int i = 0; i < matrix1.size(); i++) {

		int pivotCol = -1;
		for (int j = 0; j < matrix1[0].size(); j++) {
			if (fabs(matrix1[i][j]) > 1e-10) {
				pivotCol = j;
				break;
			}
		}
		if (pivotCol == -1) continue;
		double pivotVal = matrix1[i][pivotCol];
		for (int j = pivotCol; j < matrix1[0].size(); j++) {
			matrix1[i][j] /= pivotVal;
		}
	}

	for (int i = matrix1.size() - 1; i >= 0; i--) {
		int pivotCol = -1;
		for (int j = 0; j < matrix1[0].size(); j++) {
			if (fabs(matrix1[i][j]) > 1e-10) {
				pivotCol = j;
				break;
			}
		}
		if (pivotCol == -1) continue;
		for (int r = 0; r < i; r++) {
			double factor = matrix1[r][pivotCol];
			for (int c = pivotCol; c < matrix1[0].size(); c++) {
				matrix1[r][c] -= factor * matrix1[i][c];
			}
		}
	}

	for (int i = 0;i < matrix1.size();i++) {
		bool all0 = true;
		for (int k = 0;k < matrix1[i].size();k++) {
			if (fabs(matrix1[i][k]) > 1e-10) {
				all0 = false;
				break;
			}
		}
		if (!all0) {
			rankA++;
		}
	}
	//matrix1 end

	//matrix2 start
	for (int ind = 0;ind < min(m, n);ind++) {
		int bigRow = ind;
		for (int i = ind + 1; i < matrix2.size(); i++) {
			if (fabs(matrix2[i][ind]) > fabs(matrix2[bigRow][ind])) {
				bigRow = i;
			}
		}
		if (bigRow != ind) {
			for (int k = 0; k < matrix2[0].size(); k++) {
				double temp = matrix2[ind][k];
				matrix2[ind][k] = matrix2[bigRow][k];
				matrix2[bigRow][k] = temp;
			}
		}
		if (fabs(matrix2[ind][ind]) < 1e-10) {
			continue;
		}
		for (int i = 0; i < matrix2.size(); i++) {
			if (i <= ind) {
				continue;
			}
			double multi = -(matrix2[i][ind] / matrix2[ind][ind]);
			for (int k = ind; k < matrix2[0].size(); k++) {
				matrix2[i][k] += (multi * matrix2[ind][k]);
			}
		}
	}

	for (int i = 0; i < matrix2.size(); i++) {

		int pivotCol = -1;
		for (int j = 0; j < matrix2[0].size(); j++) {
			if (fabs(matrix2[i][j]) > 1e-10) {
				pivotCol = j;
				break;
			}
		}
		if (pivotCol == -1) continue;
		double pivotVal = matrix2[i][pivotCol];
		for (int j = pivotCol; j < matrix2[0].size(); j++) {
			matrix2[i][j] /= pivotVal;
		}
	}

	for (int i = matrix2.size() - 1; i >= 0; i--) {
		int pivotCol = -1;
		for (int j = 0; j < matrix2[0].size(); j++) {
			if (fabs(matrix2[i][j]) > 1e-10) {
				pivotCol = j;
				break;
			}
		}
		if (pivotCol == -1) continue;
		for (int r = 0; r < i; r++) {
			double factor = matrix2[r][pivotCol];
			for (int c = pivotCol; c < matrix2[0].size(); c++) {
				matrix2[r][c] -= factor * matrix2[i][c];
			}
		}
	}

	for (int i = 0;i < matrix2.size();i++) {
		bool all0 = true;
		for (int k = 0;k < matrix2[i].size();k++) {
			if (fabs(matrix2[i][k]) > 1e-10) {
				all0 = false;
				break;
			}
		}
		if (!all0) {
			rankB++;
		}
	}
	//matrix2 end

	if (rankA != rankB) {
		cout << "No," << rankA << "," << rankB ;
		return;
	}
	bool same = true;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (fabs(matrix1[i][j] - matrix2[i][j]) > 1e-3) {
				same = false;
				break;
			}
		}
		if (!same) break;
	}

	if (same) {
		cout << "Yes," << rankA ;
	}
	else {
		cout << "No," << rankA << "," << rankB ;
	}

	return;
}


int main(int argc, char* argv[])
{
	ifstream fin;
	fin.open(argv[1]);
	//fin.open("in_1.txt");
	string input;
	int ind = 0;
	
	while (getline(fin,input))
	{
		

		ind = ind % 3;
		if (ind == 0) {
			m = 0;
			n = 0;
			int st;
			for (int i = 0;i < input.size();i++) {
				if (input[i] == ' ') {
					st = i + 3;
					break;
				}
				else {
					m = m * 10 + (input[i] - '0');
				}
			}
			for (int i = st;i < input.size();i++) {
				n = n * 10 + (input[i] - '0');
			}
		}
		else if (ind == 1) {
			matrix1.clear();
			vector<double>tmpVt;
			int cnt = 0;
			double tmp1 = 0;
			for (int i = 0;i < input.size();i++) {
				if (cnt == n) {
					cnt = 0;
					matrix1.push_back(tmpVt);
					tmpVt.clear();
				}
				if (input[i] == ' ') {
					tmpVt.push_back(tmp1);
					tmp1 = 0;
					cnt++;
				}
				else {
					tmp1 = tmp1 * 10 + (input[i] - '0');
				}
				if (i == input.size() - 1) {
					tmpVt.push_back(tmp1);
					matrix1.push_back(tmpVt);
				}
			}
		}
		else {
			matrix2.clear();
			vector<double>tmpVt;
			int cnt = 0;
			double tmp1 = 0;
			for (int i = 0;i < input.size();i++) {
				if (cnt == n) {
					cnt = 0;
					matrix2.push_back(tmpVt);
					tmpVt.clear();
				}
				if (input[i] == ' ') {
					tmpVt.push_back(tmp1);
					tmp1 = 0;
					cnt++;
				}
				else {
					tmp1 = tmp1 * 10 + (input[i] - '0');
				}
				if (i == input.size() - 1) {
					tmpVt.push_back(tmp1);
					matrix2.push_back(tmpVt);
				}
			}
			/*for (int i = 0;i < matrix1.size();i++) {
				for (int k = 0;k < matrix1.size();k++) {
					cout << matrix1[i][k] << " ";
				}
				cout << endl;
			}
			for (int i = 0;i < matrix2.size();i++) {
				for (int k = 0;k < matrix2.size();k++) {
					cout << matrix2[i][k] << " ";
				}
				cout << endl;
			}*/
			if (t != 0) {
				cout << endl;
			}
			solve();
			t++;
		}
		ind++;
	}
}