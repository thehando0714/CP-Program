
#include<iostream>
#include<string>
#include<vector>
#include<cstring>
using namespace std;
vector<string>input1, input2;
int dp[100][100]{};
vector<string>lcs;
void print(int x, int y) {
	if (x == 0 || y == 0) {
		return;
	}
	if (input1[x-1] == input2[y-1]) {
		print(x - 1, y - 1);
		lcs.push_back(input1[x - 1]);
		
	}
	else if (dp[x - 1][y] >= dp[x][y - 1]) {
		print(x - 1, y);
	}
	else {
		print(x, y - 1);
	}
}
int main(){
	
	string tmp1;
	int t = 0;
	while (true)
	{
		if (t != 0) {
			cout << "\n";
		}
		input1.clear();
		input2.clear();
		memset(dp, 0, sizeof(dp)); 
		lcs.clear();
		if (!(cin >> tmp1)) break;

		// 讀完整個 input1
		if (tmp1 != "#") input1.push_back(tmp1);
		while (cin >> tmp1 && tmp1!="#")
		{
			input1.push_back(tmp1);
		}
		while (cin>>tmp1&&tmp1!="#")
		{
			input2.push_back(tmp1);
		}
		for (int i = 1;i <= input1.size();i++) {
			dp[i][0] = 0;
		}
		for (int i = 1;i <= input2.size();i++) {
			dp[0][i] = 0;
		}
		for (int i = 1;i <= input1.size();i++) {
			for (int k = 1;k <= input2.size();k++) {
				if (input1[i - 1] == input2[k - 1]) {
					dp[i][k] = dp[i - 1][k - 1] + 1;
				}
				else {
					dp[i][k] = max(dp[i - 1][k], dp[i][k - 1]);
				}
			}
		}
		print(input1.size() , input2.size() );
		for (int i = 0; i < lcs.size(); i++) {
			if (i > 0) cout << " ";
			cout << lcs[i];
		}
		t++;
		
	}
	
}