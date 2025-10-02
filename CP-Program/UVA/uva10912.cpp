#include<iostream>
#include<vector>

using namespace std;
int dp[27][27][352];
int main() {
    int l, s,cases = 0;
    dp[0][0][0] = 1;
    for (int i = 1;i <= 26;i++) {
        for (int j = 0;j <= i;j++) {
            for (int k = 0;k <= 351;k++) {
                dp[i][j][k] = dp[i - 1][j][k];
                if (j && k >= i)dp[i][j][k] += dp[i - 1][j - 1][k - i];
            }
        }
    }
    while (cin>>l>>s,l&&s)
    {
        cout << "Case " << ++cases << ": ";
        if (l > 26 || s > 351) {
            cout << "0";
        }
        else {
            cout << dp[26][l][s];
        }
        cout << "\n";
    }
}