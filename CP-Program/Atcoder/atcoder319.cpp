#include<bits/stdc++.h>

using namespace std;

string name[10]{"tourist","ksun48","Benq","Um_nik","apiad","Stonefeang","ecnerwala","mnbvmar","newbiedmy","semiexp"};
int record[10]{3858,3679,3658,3648,3638,3630,3613,3555,3516,3481};
string input;
int where;
bool getfind;
int main(){
    getline(cin,input);
    for(int i=0;i<10;i++){
        if(input.size()==name[i].size()){
            for(int k=0;k<input.size();k++){
                if(input[k]!=name[i][k]){
                    break;
                }
                if(k==input.size()-1){
                    getfind=true;
                    where=i;
                }      
            }
        }
    }
    cout<<record[where]<<"\n";
    return 0;
}