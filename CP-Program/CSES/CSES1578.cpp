class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        vector<int>dp(colors.size()+1);
        dp[0]=0;
        for(int i=1;i<colors.size();i++){
            if(colors[i]!=colors[i-1]){
                dp[i]=dp[i-1];
            }
            else{
                int prev=i-1;
                for(int k=i;k<colors.size();k++){
                    if(colors[k]==colors[prev]){
                        if(neededTime[k]>neededTime[prev]){
                            dp[k]=dp[k-1]+neededTime[prev];
                            prev=k;
                        }
                        else{
                            dp[k]=dp[k-1]+neededTime[k];
                        }
                        i=k;
                    }
                    else{
                        break;
                    }
                    /*else{
                        i=k-1;
                        break;
                    }*/
                    
                }
            }
            
        }
        return dp[colors.size()-1];
    }
};