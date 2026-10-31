#include<bits/stdc++.h>
using namespace std;

vector<vector<int>adj;
vector<unordered_set<int>>bcc;
vector<int>dist,low;
vector<bool>iscut;
stack<pair<int,int>>st;
int dep;


void dfs(int u,int par){

    int child=0;
    dist[u]=low[u]=++dep;
    for(auto& v:adj[u]){
        if(!dist[v]){
            child++;
            st.push({u,v});
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){
                iscut[u]=true;
                unordered_set<int>us;
                while(true){
                    int cu=st.top().first,cv=st.top().second;
                    st.pop();
                    us.insert(cu);
                    us.insert(cv);
                    if(cn==u&&cv==v)break;
                }
                bcc.insert(us);

            }
            else if(dfn[v]<dfn[u]&&v!=par){
                low[u]=min(low[u],dfn[v]);
            }

        }
        if(par==-1&&child==1)iscut[u]=false;



    }


}


int main(){
    int n.cases=0;
    while(cin>>n,n){
        adj.assign(n+2,vector<int>());
        bcc.clear();
        dist.assign(n+2,0);
        low.assign(n+2,0);
        iscut.assign(n+2,false);
        for(int i=0,a,b;i<n;i++){
            cin>>a>>b;
            
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1,-1);
        
        long long ans1=0,ans2=1;
        if(bcc.size())==1{
            ans1=2;
            ans2=bcc[0].size()*(bcc[0].size()-1)/2;
        }
        else {
            for(auto& i:bcc){
                int count=0;
                for(auto& j:i){
                    if(iscut[j])++count;
                }
                if(count==1){
                    ans1++;
                    ans2*=i.size()-1;
                }
            }
        }
    }


}