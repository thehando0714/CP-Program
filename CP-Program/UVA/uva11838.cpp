#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj;
vector<int>dist,low;
set<int>st;
int timer,cnt;

void dfs(int u){
    low[u]=dist[u]=++timer;
    st.insert(u);
    for(auto& v:adj[u]){
        if(!dist[v]){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(st.count(v)){
            low[u]=min(low[u],dist[v]);
        }

    }
    if(dist[u]==low[u])st.clear(),++cnt;

}




int main(){
    int n,m;
    while(cin>>n>>m,n&&m){
        adj.assign(n+1,vector<int>());
        low.assign(n+1,0);
        dist.assign(n+1,0);
        st.clear();
        timer=cnt=0;
        int v,w,p;
        while(m--){
            cin>>v>>w>>p;
            adj[v].push_back(w);
            if(p==2)adj[w].push_back(v);

        }
        for(int i=1;i<=n;i++){
            if(!dist[i]&&cnt<2){
                dfs(i);
            }
        }


        cout<<(cnt==1)<<"\n";

    }



}