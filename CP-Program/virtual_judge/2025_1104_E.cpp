#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<int>>vv(50 * 1e4, vector<int>(26.0));
vector<int>val(50 * 1e4 + 50, 0);
int node = 0;
void insert(string& tar){
    int now = 0;
    for (int i = 0;i < tar.size();i++) {
        if (vv[now][tar[i] - 'a'] == 0) {
            node++;
            vv[now][tar[i] - 'a'] = node;
            now = node;
        }
        else {
            now = vv[now][tar[i] - 'a'];
        }

    }
    val[now] = 1;
    return;
}
int query(string& tar) {
    int now = 0;
    for (int i = 0;i < tar.size();i++) {
        if (vv[now][tar[i] - 'a'] == 0) {
            return 0;
        }
        else {

            now = vv[now][tar[i] - 'a'];
            if (val[now] == 1 && i == tar.size() - 1) {
                val[now]++;
                return 1;
            }
            else if (val[now] == 2 && i == tar.size() - 1) {
                return 2;
            }
        }


    }
}

int main() {
    int n;
    cin >> n;
    string coach;
    for (int i = 0;i < n;i++) {
        cin >> coach;
        insert(coach);
    }
    int m;
    cin >> m;
    for (int i = 0;i < m;i++) {
        int ans;
        string tmp;
        cin >> tmp;
        ans=query(tmp);
        if (ans == 0) {
            cout << "WRONG\n";
        }
        else if (ans == 1) {
            cout << "OK\n";
        }
        else {
            cout << "REPEAT\n";
        }
    }
}