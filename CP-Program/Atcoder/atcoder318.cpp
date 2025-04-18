#include<bits/stdc++.h>

using namespace std;

int n,m,p,ans,tmp;

int main(){
    cin>>n>>m>>p;
    if(n>=m){
        ans++;
        while(m+p<=n){
            ans++;
            m+=p;
        }
    }
    cout<<ans<<"\n";
    return 0;
}