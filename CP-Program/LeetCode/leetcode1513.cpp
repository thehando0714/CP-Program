class Solution {
public:
    int numSub(string s) {
        long long mod=1e9+7;
        int ans=0;
        int ind=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                ans+=((ind%mod*(ind+1)%mod)%mod)/2;
                ind=0;
            }
            else{
                ind++;
            }
        }
        ans+=((ind*(ind+1))%mod)/2;
        return ans;
    }
};