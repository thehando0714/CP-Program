#include<bits/stdc++.h>

using namespace std;

int fullmap[100][100]{};
int main(){
    int n=0;
    cin>>n;
    int ans=0;
    while(n--){
        int x1,x2,y1,y2;
        cin>>x1>>x2>>y1>>y2;
        for(int i=x1;i<x2;i++){
            for(int k=y1;k<y2;k++){
                if(fullmap[i][k]==0){
                    ans++;
                    fullmap[i][k]=1;
                }
            }
        }
    }
    cout<<ans<<'\n';

}