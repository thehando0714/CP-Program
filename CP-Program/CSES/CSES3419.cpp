#include <iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n;


int main() {
    cin >> n ;
    vector<vector<int>>grid(n, vector<int>(n));
    vector<vector<bool>>used_row(n, vector<bool>(n * 2, false));
    vector<vector<bool>>used_col(n, vector<bool>(n * 2, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int mex = 0;
            while (used_row[i][mex] || used_col[j][mex])mex++;
            grid[i][j] = mex;
            used_row[i][mex] = used_col[j][mex] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j];
            if (j == n - 1) {
                cout << "\n";
            }
            else {
                cout << " ";
            }
        }
    }
    
 
}