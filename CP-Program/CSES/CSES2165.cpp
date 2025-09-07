#include<iostream>
#include<vector>


using namespace std;

int step;
vector<pair<int, int>>ans;
void hanoi(int n, int A, int B, int C) {
    if (n == 1) {
        auto tmp = make_pair(A, C);
        ans.push_back(tmp);
        step++;
    }
    else {
        hanoi(n - 1, A, C, B);
        hanoi(1, A, B, C);
        hanoi(n - 1, B, A, C);
    }
}

int main() {
    int n;
    cin >> n;
    hanoi(n, 1, 2, 3);
    cout << step << '\n';
    for (int i = 0;i < ans.size();i++) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}