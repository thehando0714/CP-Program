#include<bits/stdc++.h>
using namespace std;

bool prime[100000];



int main(){
    prime[1]=true;
    for(int i=2;i<100000;i++){
        if(!prime[i]){
            int tmp=i+i;
            while(tmp<100000){
                prime[tmp]=true;
                tmp+=i;
            }
        }
    }
   
    int n;
    while(cin>>n,n!=0){
         bool good=false;
        for(int i=2;i<100000;i++){
            if(!prime[i]&&!prime[1-i]){
                good=true;
                cout<<n<<" = "<<prime[i]<<" + "<<prime[1-i]<<"\n";
                break;
            }
            
        }
        if(!good){
            cout<<"Goldbach's conjecture is wrong.\n";
        }
    }

}