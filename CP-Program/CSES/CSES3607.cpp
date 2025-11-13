class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>>con(c+1);
        vector<bool>vis(c+1,false);
        map<int,set<int>>online;
        vector<int>parent(c+1);
        for(int i=0;i<connections.size();i++){
            int one=connections[i][0],two=connections[i][1];
            con[one].push_back(two);
            con[two].push_back(one);
        }
        for(int i=1;i<=c;i++){
            if(!vis[i]){
                set<int>qu;
                parent[i]=i;
                online[i].insert(i);
                qu.insert(i);
                while(qu.size()!=0){
                    int tar=*qu.begin();
                    qu.erase(qu.begin());
                    if(vis[tar])continue;
                    parent[tar]=i;
                    online[i].insert(tar);
                    vis[tar]=true;
                    for(int k=0;k<con[tar].size();k++){
                        if(!vis[con[tar][k]]&&!qu.count(con[tar][k])){
                            qu.insert(con[tar][k]);
                        }
                    }
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int tar=queries[i][1];
            if(queries[i][0]==1){
                if(online[parent[tar]].count(tar)){
                    ans.push_back(tar);
                    continue;
                }
                int res=-1;
                if(online[parent[tar]].size()!=0)res=*online[parent[tar]].begin();
                ans.push_back(res);
            }
            else{
                online[parent[tar]].erase(tar);
            }
        }
        return ans;
    }
};