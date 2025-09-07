#include<bits/stdc++.h>
using namespace std;

int com(){
    string s;
    cin>>s;
    if(s[0]=='f'){
        int x=com();
        return 2*x-3;
    }
    else if(s[0]=='g'){
        int x=com();
        int y=com();
        return 2*x+y-7;
    }
    else if(s[0]=='h'){
        int x=com();
        int y=com();
        int z=com();
        return 3*x-2*y+z;
    }
    else{
        return stoi(s);
    }
}

int main(){
    cout<<com()<<endl;
    return 0;
}

