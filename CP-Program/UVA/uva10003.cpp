#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
    int l, n;
    while (cin >> l&&l!=0) {
        cin >> n;
        vector<int>cut(n + 2);
        cut[0] = 0;
        for (int i = 1;i <= n;i++) {
            cin >> cut[i];
        }
        cut[n + 1] = l;
        int m = n + 2;
        vector<vector<long long>>dp(m, vector<long long>(m, 0));
        const long long INF = (1LL << 60);
        for (int len = 2;len < m;len++) {
            for (int i = 0;i + len < m;i++) {
                int j = i + len;
                long long best = INF;
                for (int k = i + 1;k <= j - 1;k++) {
                    long long cost = dp[i][k] + dp[k][j] + (cut[j] - cut[i]);
                    if (cost < best)best = cost;
                }
                if (best == INF)best = 0;
                dp[i][j] = best;
            }
        }
        cout << "The minimum cutting is " << dp[0][m - 1] << "." << endl;

        
    }

}