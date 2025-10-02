#include<iostream>
#include<vector>
using namespace std;

int main() {
    int input;
    vector<int>allIn;


    /**/while (cin >> input) {
        allIn.push_back(input);
    }
    vector<int>dp;
    vector<int>pos;
    vector<int>prev(allIn.size(), -1);

    for (int i = 0; i < allIn.size(); i++) {
        auto it = lower_bound(dp.begin(), dp.end(), allIn[i]);
        int curPos = it - dp.begin();

        if (it == dp.end()) {
            dp.push_back(allIn[i]);
        }
        else {
            *it = allIn[i];
        }
        pos.push_back(curPos);
        if (curPos > 0) {
            for (int j = i - 1; j >= 0; j--) {
                if (pos[j] == curPos - 1 && allIn[j] < allIn[i]) {
                    prev[i] = j;
                    break;
                }
            }
        }
    }
    int maxLen = dp.size();
    cout << maxLen << "\n-\n";

    vector<int> output;
    int curInd = -1;
    for (int i = allIn.size() - 1; i >= 0; i--) {
        if (pos[i] == maxLen - 1) {
            curInd = i;
            break;
        }
    }

    while (curInd!=-1)
    {
        output.push_back(allIn[curInd]);
        curInd = prev[curInd];
    }

    for (int i = output.size() - 1; i >= 0; i--) {
        cout << output[i] << endl;
    }
    return 0;
}