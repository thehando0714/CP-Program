#include<bits/stdc++.h>
using namespace std;


vector<tuple<int,int,int>>edge;
vector<int>parents;
vector<int>ranks;

bool cmp(tuple<int,int,int>a,tuple<int,int,int>b){
    return get<2>(a)<get<2>(b);
}

bool union_find(int u,int v){
    while(u!=parents[u])u=parents[u];
    while(v!=parents[v])v=parents[v];

    if(u==v)return false;

    if(ranks[u]>ranks[v])parents[v]=u;
    else if(ranks[v]>ranks[u])parents[u]=v;
    else parents[v]=u,++ranks[u];

    return true;
}

void kruskcal(){
    sort(edge.begin(),edge.end(),cmp);

    bool forest=true;
    
    for(auto& [u,v,w]:edge)if(!union_find(u,v))
    {
        if(!forest)cout<<" ";
        cout<<w;
        forest=false;
    }
    if(forest)cout<<"forest";
    cout<<"\n";
}

int main(){

    int n,m;
    while(cin>>n>>m,n||m){
        edge.clear();
        parents.clear();
        ranks.assign(n,0);
        for(int i=0;i<n;++i)parents.push_back(i);
        while(m--){
            int u,v,w;
            cin>>u>>v>>w;
            edge.push_back({u,v,w});
        }
        kruskcal();
    }
    return 0;
}