#include <iostream>
#include <queue>
#include<cstring>
#include <utility>
#include<map>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

const int maxN = 1005;
vector<vector<int>>adj(maxN);
int dfn[maxN], low[maxN];
int timer;

vector<pair<int, int>>bridge;

void findBridge(int u, int p) {
	dfn[u] = low[u] = timer;
	timer++;
	for (int i = 0;i < adj[u].size();i++) {
		if (adj[u][i] == p)continue;

		if (dfn[adj[u][i]]>0) {
			low[u] = min(low[u], dfn[adj[u][i]]);
		}
		else {
			findBridge(adj[u][i], u);
			low[u] = min(low[u], low[adj[u][i]]);

			if (low[adj[u][i]] > dfn[u]) {
				if (u < adj[u][i])bridge.push_back({ u,adj[u][i] });
				else bridge.push_back({ adj[u][i],u });
			}

		}
	}
}

int main() {
	int n;
	while (cin >> n) {
		for (int i = 0;i < n;i++) {
			adj[i].clear();
			dfn[i] = 0;
			low[i] = 0;
		}
		bridge.clear();
		timer = 0;
		for (int i = 0;i < n;i++) {
			int a, b, c;
			char ch1, ch2;
			cin >> a >> ch1 >> b >> ch2;
			while (b--) {
				cin >> c;
				adj[a].push_back(c);
				adj[c].push_back(a);
			}
		}
		for (int i = 0;i < n;i++) {
			if (dfn[i] == 0) {
				findBridge(i, -1);
			}
		}
		sort(bridge.begin(), bridge.end());
		cout << bridge.size() << " critical links\n";
		for (int i = 0;i < bridge.size();i++) {
			cout << bridge[i].first << " - " << bridge[i].second << "\n";
		}
		cout << "\n";
	}
	return 0;
}