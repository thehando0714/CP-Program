#include<iostream>
#include<string>
#include<set>
#include<sstream>
#include<cstring>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    cin.ignore();
    while (n--) {
        set<pair<int, pair<int, int>>>graph;
        string input;
        bool correct[101][10];
        memset(correct, 0, sizeof(correct));
        int punish[101][10];
        memset(punish, 0, sizeof(punish));
        while (getline(cin, input) && !input.empty())
        {

            stringstream ss(input);
            int pl, pr, ti;
            char sta;


            bool have = false;
            ss >> pl >> pr >> ti >> sta;
           

            //if (sta == 'C' || sta == 'I') {
                if (!graph.empty()) {
                    for (auto it = graph.begin();it != graph.end();it++) {
                        if (it->second.second == pl && sta == 'C') {
                            if (!correct[pl][pr]) {
                                correct[pl][pr] = true;
                                auto it2 = make_pair(it->second.first + ti + punish[pl][pr] * 20, abs(it->second.second));
                                punish[pl][pr] = 0;
                                int tmp1 = it->first;
                                tmp1--;
                                auto it3 = make_pair(tmp1, it2);
                                graph.insert(it3);
                                graph.erase(it);
                                have = true;
                                break;
                            }
                            else {
                                have = true;
                                break;
                            }
                        }
                        else if (it->second.second == pl && sta == 'I') {
                            
                            if (!correct[pl][pr]) {
                                punish[pl][pr]++;
                                have = true;
                                break;
                            }
                            else {
                                have = true;
                                break;
                            }
                        }
                    }
                }
                if (!have || graph.empty()) {
                    if (sta == 'C') {
                        correct[pl][pr] = true;
                        auto it2 = make_pair(ti, abs(pl));
                        auto it3 = make_pair(-1, it2);
                        graph.insert(it3);
                    }
                    else if (sta == 'R'|| sta == 'U'|| sta == 'E') {
                        auto it2 = make_pair(0, abs(pl));
                        auto it3 = make_pair(0, it2);
                        graph.insert(it3);
                    }
                    else {
                        punish[pl][pr]++;
                        auto it2 = make_pair(0, abs(pl));
                        auto it3 = make_pair(0, it2);
                        graph.insert(it3);
                    }
                }
          //  }
        }
        for (auto it = graph.begin();it != graph.end();it++) {
            cout << abs(it->second.second) << " " << abs(it->first) << " " << it->second.first;
            cout << "\n";
        }
        if (n) {
            cout << "\n";
        }
    }
}