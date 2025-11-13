#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    vector<long long>vtA(n, 0), vtB(m, 0);
    for (int i = 0;i < n;i++) {
        cin >> vtA[i];
    }
    for (int i = 0;i < m;i++) {
        cin >> vtB[i];
    }
    long long ans = 1e9 + 30;
    sort(vtA.begin(), vtA.end());
    sort(vtB.begin(), vtB.end());
    for (int i = 0;i < n;i++) {
        auto it=lower_bound(vtB.begin(), vtB.end(), vtA[i]);
        if (it == vtB.end()) {
            ans = min(vtA[i] - vtB[vtB.size() - 1], ans);
        }
        else{
            ans = min(abs(vtA[i] - *it), ans);
        }
    }
    for (int i = 0;i < m;i++) {
        auto it = lower_bound(vtA.begin(), vtA.end(), vtB[i]);
        if (it == vtA.end()) {
            ans = min(vtB[i] - vtA[vtA.size() - 1], ans);
        }
        else {
            ans = min(abs(vtB[i] - *it), ans);
        }
    }
    cout << ans << endl;
}
