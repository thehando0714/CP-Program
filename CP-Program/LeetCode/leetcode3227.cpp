class Solution {
public:
    bool doesAliceWin(string s) {
        set<char>vowel={'a','e','i','o','u'};
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(vowel.count(s[i])){
                ans++;
            }
        }
        if(ans!=0){
            return true;
        }
        else{
            return false;
        }
    }
};