#include<bits/stdc++.h>
using namespace std;

int main() {
    map<string, string> mymap;
    string input;
    while (getline(cin,input) && input != "") {
        size_t pos = input.find(' ');
        string tmp1 = input.substr(0, pos);//cat
        string tmp2 = input.substr(pos + 1);//ata
        mymap[tmp2] = tmp1;
    }
    while (cin >> input) {
        if (mymap.count(input)) {
            cout << mymap[input] << "\n";
        }
        else {
            cout << "eh" << "\n";
        }
    }
}