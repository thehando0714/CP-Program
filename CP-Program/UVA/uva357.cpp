#include <iostream>


using namespace std;

int n;


int main() {
    int coin[5] = { 1,5,10,25,50 };
    long long int dp[30001]{};
    dp[0] = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = coin[i]; j <= 30000; j++) {
            dp[j] += dp[j - coin[i]];
        }
    }
    while (cin >> n) {
        if (dp[n] != 1) {
            cout << "There are " << dp[n] << " ways to produce " << n << " cents change.\n";
        }
        else {
            cout << "There is only 1 way to produce " << n << " cents change.\n";
        }
    }
    
 
}