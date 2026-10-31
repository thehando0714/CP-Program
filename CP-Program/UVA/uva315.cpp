#include <iostream>
#include <queue>
#include<cstring>
#include <utility>
#include<map>
#include<string>
#include<set>
#include<algorithm>
#include<sstream>
using namespace std;

const int maxN = 1005;
vector<vector<int>>adj(maxN);
int dfn[maxN], low[maxN];
int timer;

set<int>ans;

void dfs(int u, int p) {
	dfn[u] = low[u] = timer;
	timer++;
	int child = 0;
	for (int i = 0;i < adj[u].size();i++) {
		if (adj[u][i] == p)continue;

		if (dfn[adj[u][i]]>0) {
			low[u] = min(low[u], dfn[adj[u][i]]);
		}
		else {
			child++;
			dfs(adj[u][i], u);
			low[u] = min(low[u], low[adj[u][i]]);

			if (p != -1 && low[adj[u][i]] >= dfn[u]) {
				ans.insert(u);
			}

		}
	}
	if (p == -1 && child >= 2) {
		ans.insert(u);
	}
}

int main() {
	int n;
	while (cin >> n,n) {
		for (int i = 0;i <= n;i++) {
			adj[i].clear();
			dfn[i] = 0;
			low[i] = 0;
		}
		timer = 1;
		ans.clear();
		cin.ignore();
		string line;
		while (getline(cin, line)) {
			stringstream ss(line);
			int a, b;
			ss >> a;
			if (a == 0)break;
			while (ss>>b)
			{
				adj[a].push_back(b);
				adj[b].push_back(a);
			}
		}
		dfs(1, -1);
		
		cout << ans.size()<<endl;
	}
	return 0;
}