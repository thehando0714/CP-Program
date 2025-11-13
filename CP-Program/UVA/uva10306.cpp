    #include<iostream>
#include<vector>
using namespace std;

int main() {
    int n,m,s;
    cin >> n;
    while (n--)
    {
        vector<vector<int>>dp(301, vector<int>(301, 1e8));
        cin >> m >> s;
        s *= s;
        dp[0][0] = 0;
        vector<pair<int, int>>coin;
        for (int i = 0;i < m;i++) {
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            coin.push_back({ tmp1,tmp2 });
        }
        for (int p = 0;p < coin.size();p++) {
            int con = coin[p].first,info=coin[p].second;
            for (int i = con;i <= 300;i++) {
                for (int j = info;j <= 300;j++) {
                    dp[i][j] = min(dp[i][j], dp[i - con][j - info] + 1);
                }
            }
        }
        int ans = 1e8;
        for (int i = 0;i <= 300;i++) {
            for (int k = 0;k <= 300;k++) {
                if (i * i + k * k == s)ans = min(ans, dp[i][k]);
            }
        }
        if (ans == 1e8) {
            cout << "not possible\n";
        }
        else {
            cout << ans << endl;
        }
    }
    return 0;

}