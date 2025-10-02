#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,cases=1;
    cin>>t;
    while (t--)
    {
        if(cases!=1){
            cout<<endl;
        }
        int n;
        cin>>n;
        vector<int>height,width;
        for(int i=0;i<n;i++){
            int tmp;
            cin>>tmp;
            height.push_back(tmp);
        }
        for(int i=0;i<n;i++){
            int tmp;
            cin>>tmp;
            width.push_back(tmp);
        }
        vector<int>inc(n),dec(n);
        for(int i=0;i<n;i++){
            inc[i]=width[i];
            for(int k=i-1;k>=0;k--){
                if(height[i]>height[k]){
                    inc[i]=max(inc[i],inc[k]+width[i]);
                }
            }
            
        }
        for(int i=n-1;i>=0;i--){
            dec[i]=width[i];
            for(int k=i+1;k<n;k++){
                if(height[i]>height[k]){
                    dec[i]=max(dec[i], dec[k]+width[i]);
                }
            }
        }
        int incBig=0,decBig=0;
        for(int i=0;i<inc.size();i++){
            incBig=max(incBig,inc[i]);
            decBig=max(decBig,dec[i]);
        }
        if(incBig>=decBig){
            cout<<"Case "<<cases<<". Increasing ("<<incBig<<"). Decreasing ("<<decBig<<").";
        }
        else{
            cout<<"Case "<<cases<<". Decreasing ("<<decBig<<"). Increasing ("<<incBig<<").";
        }
        cases++;
    }
    
}