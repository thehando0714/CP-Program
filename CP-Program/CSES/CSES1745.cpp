#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int big=100*1000+1;
    vector<int>vt;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        vt.push_back(tmp);
    }
    vector<bool>dp(big,false);
    dp[0]=true;
    for(int i=0;i<vt.size();i++){
        for(int k=big-1;k>=vt[i];k--){
            if(dp[k-vt[i]]){
                dp[k]=true;
            }
        }
    }
    vector<int>ans;
    for(int i=1;i<dp.size();i++){
        if(dp[i]){
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
        if(i!=ans.size()-1){
            cout<<" ";
        }
    }
    cout<<"\n";
}