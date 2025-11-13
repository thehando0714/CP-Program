#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    vector<long long>vt1(n+1);
    vector<long long>pre(n+1);
    pre[0]=0;
    for(int i=1;i<=n;i++){
        cin>>vt1[i];
        pre[i]=pre[i-1]+vt1[i];
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<pre[b]-pre[a-1]<<endl;
    }
}