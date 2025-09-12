class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[101];
        if(nums.size()<3){
            int ans=0;
            for(int i=0;i<nums.size();i++){
                ans=max(nums[i],ans);
            }
            return ans;
        }
        else if(nums.size()==3){
            return max(nums[0]+nums[2],nums[1]);
        }
        dp[0]=nums[0];
        dp[1]=nums[1];
        dp[2]=dp[0]+nums[2];
        for(int i=3;i<nums.size();i++){
            dp[i]=max(dp[i-2],dp[i-3])+nums[i];
        }
        int ans=0;
        for(int i=0;i<101;i++){
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};