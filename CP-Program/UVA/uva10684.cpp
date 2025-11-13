#include <iostream>
#include<vector>

using namespace std;

int main() {
	int n;
	while (cin >> n, n)
	{
		vector<int>info;
		while (n--)
		{
			int tmp;
			cin >> tmp;
			info.push_back(tmp);
		}
		int maxEnd = info[0];
		int ans = info[0];
		for (int i = 1;i < info.size();i++) {
			maxEnd = max(info[i], maxEnd + info[i]);
			ans = max(ans, maxEnd);
		}
		if (ans <= 0) {
			cout << "Losing streak.\n";
		}
		else {
			cout << "The maximum winning streak is " << ans << ".\n";
		}
	}
}
