#include<bits/stdc++.h>

using namespace std;

long long int n,t,ki,ans;

bool test(long long int t,vector<long long int>workTime,long long int middle){
    long long int tmp=0;
    for(.int i=0;i<workTime.size();i++){
        tmp+=middle/workTime[i];
        if(tmp>=t){
            return true;
        }
    }
    
    return false;
    

}

int main(){
    vector <long long int> workTime;
    
    cin>>n>>t;
    for(int i=0;i<n;i++){
        cin>>ki;
        workTime.push_back(ki);
    }
    long long int low=1,top=1e18,middle=0;
    while(low<=top){
        middle=(low+top)/2;
        
        if(test(t,workTime,middle)){
            top=middle-1;
            ans=middle;
        }
        else{
            low=middle+1;
        }
    }
    cout<<ans<<endl;
}

