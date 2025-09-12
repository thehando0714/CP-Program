class Solution {
public://laguage 1 2 3
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        set<int>idx1;//no langu friend
        for(int i=0;i<friendships.size();i++){
            set<int>st1;
            for(int k=0;k<languages[friendships[i][0]-1].size();k++){
                st1.insert(languages[friendships[i][0]-1][k]);
            }
            bool get=false;
            for(int k=0;k<languages[friendships[i][1]-1].size();k++){
                if(st1.count(languages[friendships[i][1]-1][k])){
                    get=true;
                    break;
                }
            }
            if(!get){
                idx1.insert(friendships[i][0]-1);
                idx1.insert(friendships[i][1]-1);
            }
        }
        map<int,set<int>>mp;
        for(auto it=idx1.begin();it!=idx1.end();it++){
            for(int i=0;i<languages[*it].size();i++){
                mp[languages[*it][i]].insert(*it);
            }
        }
        int ans=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            int tmp1=it->second.size();
            ans=max(ans,tmp1);
        }
        return idx1.size()-ans;
    }
};