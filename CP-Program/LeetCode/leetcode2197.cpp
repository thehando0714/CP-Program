class Solution {
public:
    int gcd(int a,int b){
        while(b!=0){
            int t=b;
            b=a%b;
            a=t;
        }
        return a;
    }
    int lcm(int a,int b){
        return a/gcd(a,b)*b;
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int>st;
        for(int i=0;i<nums.size();i++){
            int add=nums[i];
            while(!st.empty()&&gcd(add,st.top())>1){
                add=lcm(add,st.top());
                st.pop();
            }
            st.push(add);
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};