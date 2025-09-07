#include<bits/stdc++.h>
using namespace std;

vector<int>s;
int k;

void backtrack(vector<int>&combination,int start){
    if(combination.size()==6){
        for(int i=0;i<6;i++){
            if(i>0)cout<<" ";
            cout<<combination[i];
        }
        cout<<"\n";
        return;
    }
    for(int i=start;i<k;i++){
        combination.push_back(s[i]);
        backtrack(combination,i+1);
        combination.pop_back();
    }
}

int main(){
    bool ficase=true;
    while(cin>>k,k!=0){
        s.resize(k);
        for(int i=0;i<k;i++){
            cin>>s[i];
        }
        if(!ficase){
            cout<<"\n";
        }
        ficase=false;
        vector<int>combination;
        backtrack(combination,0);
    }
    return 0;
}