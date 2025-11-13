#include<bits/stdc++.h>
using namespace std;

int main(){
    int coin[11] = { 5,10,20,50,100,200,500,1000,2000,5000,10000 };
    long long dp[30001]{};
    dp[0] = 1;
    for (int i = 0;i < 11;i++) {
        for (int k = coin[i];k <=30000;k++) {
            dp[k] += dp[k - coin[i]];
            
        }   
    }
    double input;
    while (cin >> input && input != 0)
    {
        int mul = round(input * 100);
        cout << setw(6) << setprecision(2)<<fixed<<input << setw(17) << dp[mul] << endl;
    }
    return 0;

}