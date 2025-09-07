#include<iostream>

#include<queue>
using namespace std;
vector<int>obArr;
int n,taSum;


int com() {
	int ans = 0;
	int sum = 0;
	int left = 0;
	for (int i = 0;i < n;i++) {
		sum += obArr[i];

		while (sum > taSum && left <= i) {
			sum -= obArr[left];
			left++;
		}
		if (sum == taSum) {
			ans++;
		}
	}
	return ans;
}


int main() {
	cin >> n>>taSum;
	int ans=0;
	for (int i = 0;i < n;i++) {
		int tmp;
		cin >> tmp;
		obArr.push_back(tmp);
	}
	ans = com();
	cout << ans;
}