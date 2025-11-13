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
    sort(info.begin(),info.end());
    int ans=0;
    while(left<=right){
        if(info[left]+info[right]<=x){
            ans++;
            left++;
            right--;
        }
        else {
            right--;
            ans++;
        }
    }
    
    
    cout<<ans<<endl;
}