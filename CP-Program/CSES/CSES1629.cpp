#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    set<pair<long long ,long long>>st;
    while(n--){
        long long tmp1,tmp2;
        cin>>tmp1>>tmp2;
        
        st.insert({tmp2,tmp1});
    }
    long long ans=0;
    
    
    long long lastEnd = 0;
    for(auto it=st.begin();it!=st.end();it++){
        long long end=it->first;
        long long start=it->second;
        if(start>=lastEnd){
            ans++;
            lastEnd=end;
        }
    }
    cout<<ans<<endl;
    return 0;


}
