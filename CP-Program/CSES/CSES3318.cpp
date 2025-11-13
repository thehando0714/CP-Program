class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        map<int,int>mp;
        int left=0,right=0;
        vector<int>ans;
        while(right<=nums.size()){
            if(right-left==k){
                vector<int>vt;
                for(auto it=mp.begin();it!=mp.end();it++){
                    vt.push_back(it->second);
                }
                sort(vt.begin(),vt.end());
                
                multiset<int>ms;
                for(int i=vt.size()-1;i>=0;i--){
                    ms.insert(vt[i]);
                    if(ms.size()==x)break;
                }
                int tmpAns=0;
                for(auto it=mp.begin();it!=mp.end();it++){
                    if(ms.count(it->second)){
                        tmpAns+=-it->first*it->second;
                        auto it2=ms.find(it->second);
                        ms.erase(it2);
                    }
                    if(ms.size()==0){
                        break;
                    }
                }
                ans.push_back(tmpAns);
                mp[-nums[left]]--;
                left++;
            }
            if(right>=nums.size())break;
            mp[-nums[right]]++;
            right++;
        }
        return ans;
    }
};