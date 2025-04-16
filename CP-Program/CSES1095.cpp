#include<bits/stdc++.h>
using namespace std;

int main(){
    int testCase=0;
    cin>>testCase;
    long long int mod=1e9+7;
    for(int i=0;i<testCase;i++){
        long long int a=0,b=0;
        long long int result=1;
        cin>>a>>b;
        while (b>0)
        {
            if(b%2==1){
                result=(result*a)%mod;
            }
            a=(a*a)%mod;
            b/=2;
        }
        
        cout<<result<<endl;
    }
    return 0;
}