#include<bits/stdc++.h>

using namespace std;

int main(){
    string input;
    while(getline(cin,input)){
        list <char> ans;
        list <char>::iterator cursor=ans.begin();
        for(int i=0;i<input.size();i++){
            if(input[i]=='['){
                cursor=ans.begin();
            }
            else if(input[i]==']'){
                cursor=ans.end();
            }
            else{
                ans.insert(cursor,input[i]);
            }
        }
        for(list <char>::iterator it=ans.begin();it!=ans.end();it++){
            cout<<*it;
        }
        cout<<"\n";
    }


}