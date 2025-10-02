class Solution {
public:
    int maxFreqSum(string s) {
        set<char>vowel={'a','e','i','o','u'};
        map<char,int>voFre;
        map<char,int>coFre;
        for(char c:s){
            if(vowel.count(c)){
                voFre[c]++;
            }
            else{
                coFre[c]++;
            }
        }
        int a=0,b=0;
        for(auto it=voFre.begin();it!=voFre.end();it++){
            a=max(a,it->second);
        }
        for(auto it=coFre.begin();it!=coFre.end();it++){
            b=max(b,it->second);
        }
        return a+b;
        
    }
};