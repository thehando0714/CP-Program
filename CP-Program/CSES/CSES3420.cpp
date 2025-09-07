#include <iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

int n;
vector<int>vt1;
int main() {
    cin >> n;
    vt1.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> vt1[i];
    }
    unordered_set<int>us;
    int left = 0, right = 0;
    long long ans = 0;
    while (right < n) {
        while (us.count(vt1[right])) {
            us.erase(vt1[left]);
            
            left++;
        }
        us.insert(vt1[right]);
        ans += right - left + 1;
        right++;
    }
    cout << ans;

}