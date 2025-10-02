
#include<iostream>
#include<vector>

using namespace std;

int main(){
	int inp;
	vector<int>info;
	int t = 1;
	while (cin>>inp)
	{
		if (inp != -1) {
			info.push_back(inp);
		}
		else {
			if (info.empty()) {
				return 0;
			}
			if (t != 1) {
				cout << "\n";
			}
			vector<int>lis(info.size());
			int ans = 0;
			for (int i = 0;i < info.size();i++) {
				lis[i] = 1;
				for (int k = i - 1;k >= 0;k--) {
					if (info[i] <= info[k]) {
						lis[i] = max(lis[i], 1 + lis[k]);
					}
				}
				ans = max(ans, lis[i]);
			}
			cout << "Test #" << t << ":\n  maximum possible interceptions: " << ans<<"\n";
			t++;
			info.clear();
		}
	}
}