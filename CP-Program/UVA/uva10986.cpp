#include<bits/stdc++.h>
//#include<iostream>
//#include<vector>
using namespace std;
const long long big=1e18;
vector<vector<pair<long long,long long>>>adj;//end dis
vector<long long>dist;
void dij(int start){
    priority_queue<pair<long long,int>,vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0,start});
    while(!pq.empty()){
        long long d=pq.top().first;
        int u=pq.top().second;
        pq.pop();

        if(d>dist[u])continue;

        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i].first;
            long long weight=adj[u][i].second;
            if(dist[u]+weight<dist[v]){
                dist[v]=dist[u]+weight;
                pq.push({dist[v],v});
            }
        }

    }
}
int main(){
    int n,cases=1;
    cin>>n;
    
    while(n--){
        int q,m,s,t;
        cin>>q>>m>>s>>t;
        adj.assign(q,vector<pair<long long,long long>>{});
        dist.assign(q,big);
        dist[s]=0;
        for(int i=0;i<m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        dij(s);
        cout<<"Case #"<<cases<<": ";
        if(dist[t]==big){
            cout<<"unreachable\n";
        }
        else{
            cout<<dist[t]<<"\n";
        }
        cases++;
    }


}