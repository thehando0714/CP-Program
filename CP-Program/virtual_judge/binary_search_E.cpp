#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,x;
    cin>>n;
    vector<long long>info(n);
    for(int i=0;i<n;i++){
        cin>>info[i];
    }
    sort(info.begin(),info.end());
    long long tar=info[n/2];
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=abs(info[i]-tar);
    }
    cout<<ans<<endl;
}