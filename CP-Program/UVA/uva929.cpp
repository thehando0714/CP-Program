#include <iostream>
#include <queue>
#include<cstring>
#include <utility>
using namespace std;

int n,m;
int map[1001][1001];
int vals[1001][1001];
bool vis[1001][1001];
int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int> >>>pq;

void dij(){
    vals[0][0]=map[0][0];
    pq.push({map[0][0],{0,0}});

    while(!pq.empty()){

        auto [val,coords]=pq.top();
        int x=coords.first;
        int y=coords.second;

        pq.pop();

        if(val>vals[x][y])continue;

        vis[x][y]=true;

        for(int i=0;i<4;i++){
            int nx=x+d[i][0];
            int ny=y+d[i][1];

            if(nx>=0&&ny>=0&&nx<n&&ny<m&&!vis[nx][ny]){
                int tmp=val+map[nx][ny];

                if(vals[nx][ny]==-1||vals[nx][ny]>tmp){
                    vals[nx][ny]=tmp;
                    pq.push({tmp,{nx,ny}});
                }

            }

        }

    }
    cout<<vals[n-1][m-1]<<"\n";
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>m;

        memset(map,0,sizeof(map));
        memset(vis,false,sizeof(vis));
        memset(vals,-1,sizeof(vals));

        pq=priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int> >>>();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val;
                cin>>val;
                map[i][j]=val;
            }
        }
        
        dij();
    }
    
}