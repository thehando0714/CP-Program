// Online C++ compiler to run C++ program online
#include <iostream>
#include<unordered_set>
#include <algorithm>
#include<vector>
using namespace std;

int main() {
    int ts, n;
    cin >> ts;
    while (ts--) {
        int total = 0;
        cin >> n;
        vector<int>vc(n);
        unordered_set<int>us;
        for (int i = 0; i < n; i++) {
            cin >> vc[i];
        }
        int left = 0;
        for (int right = 0; right < n; right++) {
            int tmp = vc[right];
            
            while (us.count(tmp)) {
                us.erase(vc[left]);
                left++;
            }
            us.insert(tmp);
            total = max(total, right - left + 1);
        }
        cout << total << endl;
    }
    return 0;
}