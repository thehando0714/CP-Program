#include<iostream>

using namespace std;
int n, k;
const int maxn  = 50005;
int input[maxn];
long long lps[maxn], rps[maxn];

int cut(int l, int r, int level) {
	if (r - l < 2 || level >= k) {
		return 0;
	}
	long long delta = 0;
	lps[l] = 0;
	for (int i = l + 1;i < r;i++) {
		delta += input[i - 1];
		lps[i] = lps[i - 1] + delta;
	}
	delta = 0;
	rps[r] = 0;
	for (int i = r - 1;i >= l;i--) {
		delta += input[i + 1];
		rps[i] = rps[i + 1] + delta;

	}

	long long mn = 2e18;
	int idx = 0;
	for (int i = l + 1;i <= r - 1;i++) {
		long long cost = abs(rps[i] - lps[i]);
		if (cost < mn) {
			mn = cost;
			idx = i;
		}
	}
	return input[idx] + cut(l, idx - 1, level + 1) + cut(idx + 1, r, level + 1);
}

int main() {
	cin >> n >> k;
	for (int i = 1;i <= n;i++) {
		cin >> input[i];
	}
	cout << cut(1, n, 0);
}