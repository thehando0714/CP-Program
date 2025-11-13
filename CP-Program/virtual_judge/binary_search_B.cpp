#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<long long>app(n);
    multiset<long long>apart;
    for(int i=0;i<n;i++){
        cin>>app[i];
    }
    for(int i=0;i<m;i++){
        int tmp;
        cin>>tmp;
        apart.insert(tmp);
    }
    sort(app.begin(),app.end());
    int ans=0,st=0;
    for(int i=0;i<n;i++){
        long long tar=app[i]-k;
        auto it=apart.lower_bound(tar);
        if(it!=apart.end()){
            if(*it<=app[i]+k){
                ans++;
                apart.erase(it);
            }
        }
    }
    cout<<ans<<endl;
}