#include<bits/stdc++.h>

using namespace std;
int n,ans;

int com(int b){
    if(b==1)return 1;
    return com(b-1)*b;

}

int main(){
    while(cin>>n){
        
        if(n==0){
            cout<<"0! = 1 = 1\n";  
        }
        else{
            ans=com(n);
            cout<<n<<"! = ";
            for(int i=n;i>=1;i--){
                if(i!=1){
                    cout<<i<<" * ";
                }
                else{
                    cout<<i<<" = ";
                }
            }
            cout<<ans<<'\n';
        }
        
        

    }
    return 0;
}
