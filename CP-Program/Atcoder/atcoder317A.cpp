#include<bits/stdc++.h>
using namespace std;

int n,h,x;
int vt[110]{};

bool valid(int idx,int right){
    return h+vt[idx]<x&&idx<=right;
}

int  jump(int left,int right){
    int step=n+10,res=left;
    while(step>0){
        if(valid(res+step,right))res+=step;
        else step/=2;
    }
    return res+1;
}

int main(){
    cin>>n>>h>>x;
    for(int i=1;i<=n;i++){
        cin>>vt[i];
    }
    
    cout<<jump(0,n)<<endl;
}