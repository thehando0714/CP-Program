#include<bits/stdc++.h>

using namespace std;



int main(){
    int h,w;
    cin>>h>>w;
    vector <int>ans(w);
    cin.ignore();
    for(int i=0;i<h;i++){
        string tmp;
        getline(cin,tmp);
        for(int k=0;k<w;k++){
            if(tmp[k]=='#'){
                ans[k]++;
            }
        }
    }
    for(int i=0;i<w;i++){
        cout<<ans[i]<<" ";
    }
    cout<<'\n';
    return 0;
}