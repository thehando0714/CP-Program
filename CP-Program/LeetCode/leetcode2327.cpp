class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<pair<int,vector<int>>>vt;
       
        int day=1;
        int count=0;
        vector<int>vt2{1};
        auto it=make_pair(1,vt2);
        vt.push_back(it);
        day++;
        while(day<=n){
            vector<int>tmpvt;
            for(int i=count;i<vt.size();i++){
                if(day-vt[i].first>=forget){
                    count++;
                    continue;
                }
                if(day-vt[i].first>=delay){
                    tmpvt.push_back(vt[i].second.size());
                }
            }
            auto it2=make_pair(day,tmpvt);
            vt.push_back(it2);
            day++;
        }
         if(day-vt[count].first>=forget){
                    count++;
                   
                }
        int ans=0;
        for(int i=count;i<vt.size();i++){
            for(int k=0;k<vt[i].second.size();k++){
                ans+=vt[i].second[k];
            }
        }
        return ans;
    }
};