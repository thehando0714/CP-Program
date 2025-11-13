#include <iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;



int main() {
	int n, q, d, m;
	int a, cases = 0;
	long long dp[201][11];
	
	while (cin>>n>>q,n&&q)
	{
		vector<int>num;
		while (n--)
		{
			cin >> a;
			num.push_back(a);
		}
		cout << "SET " << ++cases << ":\n";

		for (int i = 1;i <= q;i++) {
			cin >> d >> m;

			vector<int>num2;
			long long ans = 0;
			memset(dp, 0, sizeof(dp));

			for (auto& j : num) {
				if (j % d > 0) {
					num2.push_back(j % d);
				}
				else {
					num2.push_back(j % d + d);
				}
			}
			dp[0][0] = 1;
			for (int f = 0;f < num2.size();f++) {
				for (int j = 200;j >= num2[f];j--) {
					for (int k = m;k > 0;k--) {
						dp[j][k] += dp[j - num2[f]][k - 1];
					}
				}
			}
			for (int j = 0;j <= 200;j += d) {
                
				ans += dp[j][m];
			}
		    cout << "QUERY " << i << ": " << ans << "\n";
        }

	}
	return 0;
}
