#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin>>n,n!=0){
        int x,y,z,d;
        cin>>x>>y>>z>>d;
        int lowx=x;
        int lowy=y;
        int lowz=z;
        int highx=x+d;
        int highy=y+d;
        int highz=z+d;
        for(int i=1;i<n;i++){
            cin>>x>>y>>z>>d;
            lowx=max(lowx,x);
            lowy=max(lowy,y);
            lowz=max(lowz,z);
            highx=min(highx,x+d);
            highy=min(highy,y+d);
            highz=min(highz,z+d);
        }
        int truex=highx-lowx;
        int truey=highy-lowy;
        int truez=highz-lowz;
        int ans=max(0,truex*truey*truez);
        cout<<ans<<endl;
    }
}