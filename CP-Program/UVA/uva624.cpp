#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        int t;
        cin>>t;
        vector<int>vt1(t+1);
        for(int i=1;i<=t;i++){
            cin>>vt1[i];
        }
        vector<vector<int>>dp(21,vector<int>(n+1,0));
        for(int i=1;i<=t;i++){
            int tmp=vt1[i];
            for(int j=0;j<=n;j++){
                if(j<tmp){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-tmp]+tmp);
                }
            }
        }
        int ans=dp[t][n];

        vector<int>path;
        int now=n;
        for(int i=t;i>0;i--){
            if(dp[i][now]!=dp[i-1][now]){
                path.push_back(vt1[i]);
                now-=vt1[i];
            }
        }
        for(int i=path.size()-1;i>=0;i--){
            cout<<path[i]<<" ";
        }
        cout<<"sum:"<<ans<<"\n";

    }


}