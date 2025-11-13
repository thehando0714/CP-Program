#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,x;
    cin>>n>>x;
    multiset<long long>ticket;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        ticket.insert(tmp);
    }
    vector<long long>ans;
    while(x--){
        int tar;
        cin>>tar;
        if(ticket.size()==0){
            ans.push_back(-1);
            continue;
        }
        auto it=ticket.lower_bound(tar);
        if(it==ticket.end()){
            it--;
            ans.push_back(*it);
            ticket.erase(it);
        }
        else if(*it==tar){
            ans.push_back(*it);
            ticket.erase(it);
        }
        else if(it==ticket.begin()&&*it>tar){
            ans.push_back(-1);
        }
        else{
            it--;
            ans.push_back(*it);
            ticket.erase(it);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    
}