class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int ans=1;
        set<char>bad;
        for(int i=0;i<brokenLetters.size();i++){
            bad.insert(brokenLetters[i]);
        }
        bool mi=false;
        for(int i=0;i<text.size();i++){
            if(text[i]==' '){
                ans++;
                mi=false;
            }
            else if(bad.count(text[i])&&!mi){
                ans--;
                mi=true;
            }
        }
        return ans;
    }
};