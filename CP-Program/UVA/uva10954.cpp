#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        priority_queue<long long int, vector<long long int>, greater<long long int>> arr;
        for (int i = 0;i < n;i++) {
            long long int tmp;
            cin >> tmp;
            arr.push(tmp);
        }
        long long ans = 0;
        while (arr.size()>1) {
            int sum;
            long long int first = arr.top();
            arr.pop();
            long long int sec = arr.top();
            arr.pop();
            
            sum = first + sec;
            ans += sum;
            arr.push(sum);
        }
        cout << ans << endl;
    }
}