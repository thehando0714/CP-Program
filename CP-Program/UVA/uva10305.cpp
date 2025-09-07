#include<iostream>
#include<vector>
using namespace std;

int n, m;
vector<vector<int>>graph;
vector<int> result;
vector<bool>visit;

void dfs(int a) {
	visit[a] = true;
	for (int i = 0;i < graph[a].size();i++) {
		if (!visit[graph[a][i]]) {
			dfs(graph[a][i]);
		}
	}
	result.push_back(a);
}

int main() {
	while (cin >> n >> m) {
		if (n == 0 && m == 0) {
			return 0;
		}
		graph.assign(n, vector<int>());
		visit.assign(n, false);
		result.clear();
		for (int i = 0;i < m;i++) {
			int tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			graph[tmp2 - 1].push_back(tmp1 -1);
		}
		for (int i = 0;i < n;i++) {
			if (!visit[i]) {
				dfs(i);
			}
		}
		//reverse(result.begin(), result.end());
		for (int i = 0; i < n; ++i) {
			cout << result[i] + 1 ;
			if (i == n - 1) {
				cout << "\n";
			}
			else {
				cout << " ";
			}
		}
	}

}