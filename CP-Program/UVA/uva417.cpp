#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
using namespace std;
vector<string> words;
int main() {
    queue<pair<string, char>> q;
    for (char c = 'a'; c <= 'z'; c++) {
        q.push({ string(1, c), c });
    }

    while (!q.empty()) {
        
        string current = q.front().first;
        char last = q.front().second;
        q.pop();

        words.push_back(current);

        if (current.size() < 5) {
            for (char c = last + 1; c <= 'z'; c++) {
                q.push({ current + c, c });
            }
        }
    }
    map<string, int> dict;
    for (int i = 0; i < (int)words.size(); i++) {
        dict[words[i]] = i + 1; 
    }

   
    string word;
    while (cin >> word) {
        if (dict.count(word)) cout << dict[word] << "\n";
        else cout << 0 << "\n";
    }
}
