class Solution {
public:
    string sortVowels(string s) {
        string ans=s;
        set <char>vowel={'a','e','i','o','u','A','E','I','O','U'};
        vector<int>ind;
        vector<char>needSort;
        for(int i=0;i<s.size();i++){
            if(vowel.count(s[i])){
                ind.push_back(i);
                needSort.push_back(s[i]);
            }
        }
        sort(needSort.begin(),needSort.end());
        for(int i=0;i<ind.size();i++){
            ans[ind[i]]=needSort[i];
        }
        return ans;

    }
};