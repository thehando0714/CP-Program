#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(cin>>n,n){
        multiset<int>bills;
        long long int totalCost=0;
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            for(int j=0;j<k;j++){
                int x;
                cin>>x;
                bills.insert(x);
            }
            multiset<int>::iterator it1=bills.begin();
            multiset<int>::iterator it2=prev(bills.end());
            totalCost+=*it2-*it1;
            bills.erase(it1);
            bills.erase(it2);
        }
        cout<<totalCost<<'\n';
    }
    return 0;
}