#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    vector<int>info(n);
    long long sum=0;
    for(int i=0;i<n;i++){
        cin>>info[i];
        sum+=info[i];
    }
    sort(info.begin(),info.end());
    long long  tar=info[n/2];
    long long ans1=0;
    for(int i=0;i<n;i++){
        ans1+=abs(info[i]-tar);
    }
    long long ans2=1e18;
    if(n/2>0){
        ans2=0;
        tar=info[(n/2)-1];
        for(int i=0;i<n;i++){
            ans2+=abs(info[i]-tar);
        }
    }
    cout<<min(ans1,ans2)<<endl;
    return 0;
}