#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	cin.ignore();
	vector<string>input;
	for (int i = 0; i < h; i++) {
		string tmp;
		getline(cin, tmp);
		input.push_back(tmp);
	}

	int dx[4] = {1, -1, 0, 0};
	int dy[4] = { 0, 0, 1, -1 };
	for (int i = 0; i < h; i++) {
		for (int k = 0; k < w; k++) {
			if (input[i][k] == '#') {
				int tmp1=0;
				for (int g = 0; g < 4; g++) {
					if (i + dx[g] >= 0 && i + dx[g] < h && k + dy[g]>=0 && k + dy[g] < w&&input[i+dx[g]][k+dy[g]]=='#') {
						tmp1++;
					}
				}
				if (tmp1 != 2 && tmp1 != 4) {
					
					cout << "No" << endl;
					return 0;
				}
			}
		}
	}
	cout << "Yes" << endl;
}
