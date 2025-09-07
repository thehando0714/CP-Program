#include <iostream>
#include<vector>

using namespace std;

vector<int> graph;
vector<int> reach,sum;
int times;


void dfs(int num) {
	++times;
	sum[num] = reach[num] = true;
	if (!reach[graph[num]])dfs(graph[num]);
}


int main() {
	int t;
	
	cin >> t;
	int tt = 1;
	while (t--) {
		
		int n;
		
		cin >> n;
		
		graph.assign(n + 1, -1);
		sum.assign(n + 1, false);

		for (int i = 1;i <= n;i++) {
			int tmp1;
			cin >> tmp1;
			cin >> graph[tmp1];
		}
		int minn = -1;
		int idx;
		for (int i = 1;i <= n;i++) {
			if (!sum[i]) {
				reach.assign(n + 1, false);
				reach[i] = true;
				times = 1;
				dfs(graph[i]);
				if (times > minn) {
					minn = times;
					idx = i;
				}
			}
		}
		cout << "Case " << tt << ": " << idx<<endl;
		tt++;
	}



}