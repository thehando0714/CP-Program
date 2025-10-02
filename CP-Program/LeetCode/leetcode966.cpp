class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        set<char>vowel={'a','e','i','o','u','A','E','I','O','U'};
        unordered_set<string>same(wordlist.begin(),wordlist.end());
        unordered_map<string,string>smWord;
        unordered_map<string,string>voWord;
        for(int i=0;i<wordlist.size();i++){
            string small;
            string vo;
            for(int k=0;k<wordlist[i].size();k++){
                small+=tolower(wordlist[i][k]);
                if(vowel.count(wordlist[i][k])){
                    vo+='a';
                }
                else{
                    vo+=tolower(wordlist[i][k]);
                }
            }
            if(!smWord.count(small))smWord[small]=wordlist[i];
            if(!voWord.count(vo))voWord[vo]=wordlist[i];
        }
        vector<string>ans;
        for(int i=0;i<queries.size();i++){
            
            if(same.count(queries[i])){
                ans.push_back(queries[i]);
                continue;
            }
                string small;
                for(int k=0;k<queries[i].size();k++){
                    small+=tolower(queries[i][k]);
                }
                
                if(smWord.count(small)){
                    ans.push_back(smWord[small]);
                    continue;
                }
                string vow;
                for(int k=0;k<queries[i].size();k++){
                    if(vowel.count(queries[i][k])){
                        vow+='a';
                    }
                    else{
                        vow+=tolower(queries[i][k]);
                    }
                }
                if(voWord.count(vow)){
                    ans.push_back(voWord[vow]);
                    continue;
                }
                string em="";
                ans.push_back(em);
        }
        return ans;
    }
    
};