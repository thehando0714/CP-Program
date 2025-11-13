#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k;

int main() {
	vector<int>prime;
	vector<bool>vis(1121);
	int dp[1121][15]{};
	for (int i = 2;i <= 1120;i++) {
		if (!vis[i])prime.push_back(i);
		for (int j = i * 2;j <= 1120;j += i) {
			vis[j] = true;
		}
	}
	dp[0][0] = 1;
	for (int k = 0;k < prime.size();k++) {
		for (int i = 1120;i >= prime[k];i--) {
			for (int j = 14;j >= 1;j--) {
				dp[i][j] += dp[i - prime[k]][j - 1];
			}
		}
	}
	
	while (cin>>n>>k,n&&k)
	{
		
		cout << dp[n][k]<<"\n";
		
	}
	return 0;
}
