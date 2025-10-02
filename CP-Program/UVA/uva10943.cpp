#include<iostream>
#include<vector>
using namespace std;
int dp[101][101];
int main() {
	int n, k;
	for (int i = 0;i < 101;i++) {
		dp[i][1] = 1;
	}
	for (int i = 0;i < 101;i++) {
		for (int j = 1;j < 101;j++) {
			for (int k = 0;k <= i;k++) {
				dp[i][j] = (dp[i][j] + dp[i - k][j - 1]) % 1000000;
			}
		}
	}
	while (cin >> n >> k, n && k) {
		cout << dp[n][k] << endl;
	}
}