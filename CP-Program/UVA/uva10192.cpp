
#include<iostream>
#include<string>
using namespace std;
int dp[1000][1000];
int main(){
	string str1, str2;
	int cases = 1;
	while (true)
	{
		getline(cin, str1);
		if (str1 == "#") {
			return 0;
		}
		getline(cin, str2);
		
		for (int i = 0;i <=str1.size();i++) {
			dp[i][0] = 0;
		}
		for (int i = 0;i <=str2.size();i++) {
			dp[0][i] = 0;
		}
		for (int i = 1;i <= str1.size();i++) {
			for (int j = 1;j <= str2.size();j++) {
				if (str1[i-1] == str2[j-1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		cout << "Case #"<<cases<<": you can visit at most " << dp[str1.size()][str2.size()] <<" cities." << endl;
		cases++;
	}
}