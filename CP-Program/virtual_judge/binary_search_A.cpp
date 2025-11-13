#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    set<int>st;
    while(n--){
        int tmp;
        cin>>tmp;
        st.insert(tmp);
    }
    cout<<st.size()<<endl;
}