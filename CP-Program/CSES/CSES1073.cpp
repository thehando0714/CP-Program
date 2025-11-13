#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    multiset<int>info;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        auto it=info.upper_bound(tmp);
        if(it!=info.end()){
            info.erase(it);
            info.insert(tmp);
        }
        else{
            info.insert(tmp);
        }
    }
    cout<<info.size()<<endl;
    return 0;
}
