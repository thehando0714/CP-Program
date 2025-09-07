#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
using namespace std;

vector<char>list;
vector<pair<char, char>>rule;
map<char, int>trueDegree;
vector<pair<char,bool>>visited;
vector<char>result;
set<string>ans;
void topo() {
	for (int i = 0; i < list.size(); i++) {
		
		if (!visited[i].second && trueDegree[list[i]] == 0) {
			visited[i].second = true;
			result.push_back(list[i]);
			
			for (int k = 0; k < rule.size(); k++) {
				if (rule[k].first == list[i]) {
					
					trueDegree[rule[k].second]--;
				}
			}
			topo();
			result.pop_back();
			for (int k = 0; k < rule.size(); k++) {
				if (rule[k].first == list[i]) {
					
					trueDegree[rule[k].second]++;
				}
			}
			
			visited[i].second = false;
		}
	}
	if (result.size() == list.size()) {
		string ll;
		for (int i = 0; i < result.size(); i++) {
			
			ll = ll + result[i];
		}
		ans.insert(ll);
		
	}
}



int main() {
	bool www=false;
    string tmp;
	while (true) {
		list.clear();
		rule.clear();
		
		trueDegree.clear();
		visited.clear();
		result.clear();
		ans.clear();
		
		
		getline(cin, tmp);
		if (tmp.empty()) {
			return 0;
		}
		for (int i = 0; i < tmp.size(); i++) {
			if (isalpha(tmp[i])) {
				list.push_back(tmp[i]);
				
				trueDegree[tmp[i]] = 0;
				auto it2 = make_pair(tmp[i], false);
				visited.push_back(it2);
			}
		}
		string rl;
		getline(cin, rl);
		int tmp2 = 3;
		char fi, se;
		for (int i = 0; i < rl.size(); i++) {
			if (isalpha(rl[i])&&tmp2%3==0) {
				fi = rl[i];
				tmp2++;
			}
			else if (isalpha(rl[i]) && tmp2 % 3 == 1) {
				se = rl[i];
				tmp2++;
			}
			if (tmp2 % 3 == 2) {
				auto it = make_pair(fi, se);
				rule.push_back(it);
				
						trueDegree[rl[i]]++;
						
				tmp2++;
			}
		}
		topo();
		for (auto w = ans.begin(); w != ans.end(); w++) {
			cout << *w<<"\n";
		}
		
		www = true;
	}


}