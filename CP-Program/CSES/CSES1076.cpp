#include<bits/stdc++.h>


using namespace std;

int n, k, input;

int main() {
    cin >> n >> k;
    vector<int> arr1;
    int where = 0;
    int tmpwhere = 0;
    for (int i = 0;i < n;i++) {
        cin >> input;
        arr1.push_back(input);
    }
    multiset<int> smallArr;
    multiset <int> bigArr;
    if(k!=1){
    for (int i = 0;i < k;i++) {
        if (smallArr.empty() || arr1[i] <= *smallArr.rbegin()) {
            smallArr.insert(arr1[i]);
        }
        else {
            bigArr.insert(arr1[i]);
        }

        while (smallArr.size() > bigArr.size() + 1) {
            bigArr.insert(*smallArr.rbegin());
            smallArr.erase(--smallArr.end());
        }
        while (smallArr.size() < bigArr.size()) {
            smallArr.insert(*bigArr.begin());
            bigArr.erase(bigArr.begin());
        }

    }
    cout << *smallArr.rbegin() << " ";
    for (int i = k;i < n;i++) {
        if (smallArr.find(arr1[i - k]) != smallArr.end()) {
            smallArr.erase(smallArr.find(arr1[i - k]));
        }
        else {
            bigArr.erase(bigArr.find(arr1[i - k]));
        }
       /* if (arr1[i] <= *smallArr.rbegin()) {
            smallArr.insert(arr1[i]);
        }*/
        if (smallArr.empty() && *bigArr.begin() < arr1[i]) {
            smallArr.insert(*bigArr.begin());
            bigArr.erase(bigArr.begin());
            bigArr.insert(arr1[i]);
        }
        else if (smallArr.empty() && *bigArr.begin() >= arr1[i]) {
            smallArr.insert(arr1[i]);
        }
        else if (arr1[i] <= *smallArr.rbegin()) {
            smallArr.insert(arr1[i]);
           
        }
        else {
            bigArr.insert(arr1[i]);
        }

        while (smallArr.size() > bigArr.size() + 1) {
            bigArr.insert(*smallArr.rbegin());
            smallArr.erase(--smallArr.end());
        }
        while (smallArr.size() < bigArr.size()) {
            smallArr.insert(*bigArr.begin());
            bigArr.erase(bigArr.begin());
        }
        cout << *smallArr.rbegin() << " ";
    }
    }
    else{
        for(int i=0;i<n;i++){
            cout<<arr1[i]<<" ";
        }
    }


    return 0;

}