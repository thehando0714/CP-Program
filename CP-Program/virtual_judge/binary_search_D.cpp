#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,x;
    cin>>n>>x;
    vector<long long>info(n);
    for(int i=0;i<n;i++){
        cin>>info[i];
    }
    int left=0,right=n-1;
    vector<long long>ob=info;
    sort(info.begin(),info.end());
    int a=-1,b=-1;
    while(left<right){
        
        if(info[left]+info[right]<x){
            left++;
        }
        else if(info[left]+info[right]>x) {
            right--;
        }
        else{
            a=left;
            b=right;
            break;
        }
    }
    
    if(a!=-1){
        for(int i=0;i<ob.size();i++){
            if(ob[i]==info[a]){
                a=i;
                break;
            }
        }
        for(int i=0;i<ob.size();i++){
            if(ob[i]==info[b]&&i!=a){
                b=i;
                break;
            }
        }
        cout<<a+1<<" "<<b+1<<endl;
    }
    else{
        cout<<"IMPOSSIBLE\n";
    }
    
}