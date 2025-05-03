#include<bits/stdc++.h>

using namespace std;

int main(){
    bool next=false;
    bool isheet=false;
    string input;
    vector <string> sheet;
    vector<int> membercount;
    set <string> name;
    while(getline(cin,input)){
        if(input[0]=='1'){
            next=true;
            for(int i=0;i<)
            continue;
        }
        
        if(next){
            if(input[0]=='0'){
                return 0;
            }
            vector <string> sheet;
            vector <vector<string>> wherename;
            set<string> name;
            
            next=false;
        }
        if(isupper(input[0])){
            sheet.push_back(input);
            
        }
        else{
            if(name.count(input)==0){
                name.insert(input);
                wherename[sheet.size()-1].push_back(input);
                
            }
            else{
                wherename[sheet.size()-1].push_back(input);
                for(int i=0;i<wherename.size();i++){
                    for(int k=0;k<wherename[i].size();k++){
                        if(wherename[i][k]==input){
                            wherename[i].erase(wherename[i].begin()+k);
                        }
                    }
                }
            }
        }


    }


}