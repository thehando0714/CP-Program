#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k;

int main() {
    while (cin >> n >> k) {
        vector<int>info(n + 1);
        int start = 0, sum = 0;

        for (int i = 0;i <= n;i++) {
            cin >> info[i];
            sum += info[i];
            start = max(start, info[i]);
        }
        int left = start, right = sum, ans = sum;
        while (left <= right) {
            int mid = (left + right) / 2;
            int day = 1, tmpSum = 0;
            for (int i = 0;i < info.size();i++) {
                if (info[i] + tmpSum > mid) {
                    day++;
                    tmpSum = 0;
                }
                tmpSum += info[i];
            }
            if (day <= k + 1) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        cout << ans << endl;
        
    }
    return 0;
}
