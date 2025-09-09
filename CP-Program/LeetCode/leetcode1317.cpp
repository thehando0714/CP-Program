class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int>ans;
        ans.push_back(1);
        ans.push_back(n-1);
        bool have=true,have2=true;
        while(have||have2){
            have=false;
            have2=false;
            int a=ans[0];
            int b=ans[1];
            while(a>0){
                if(a%10==0){
                    have=true;
                    break;
                }
                a/=10;
            }
            while(b>0){
                if(b%10==0){
                    have2=true;
                    break;
                }
                b/=10;
            }
            if(have||have2){
                ans[0]++;
                ans[1]--;
            }
        }
        return ans;
    }
};