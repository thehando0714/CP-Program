#include <iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<string>grid;
vector<string>result;
const string letters = "ABCD";

bool tryColor(char even1, char even2, char odd1, char odd2) {
    result = grid;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char oldChar = grid[i][j];
            char newChar;
            if ((i + j) % 2 == 0) {
                if (even1 != oldChar)newChar = even1;
                else if (even2 != oldChar)newChar = even2;
                else return false;
            }
            else {
                if (odd1 != oldChar)newChar = odd1;
                else if (odd2 != oldChar)newChar = odd2;
                else return false;
            }
            result[i][j] = newChar;
        }
    }
    return true;

}

int main() {
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    string perm = letters;
    do {

        if (tryColor(perm[0], perm[1], perm[2], perm[3])) {
            for (int i = 0; i < result.size(); i++) {
                cout << result[i] << endl;
            }
            return 0;
        }

    } while (next_permutation(perm.begin(), perm.end()));
    return 0;
}