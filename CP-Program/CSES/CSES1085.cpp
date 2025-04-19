#include<bits/stdc++.h>


using namespace std;

long long n, k, tmp1, ans;


bool check(long long midlle, long long k, vector<long long> xi) {
    vector <long long> tmparr;
    long long tmpsum = 0;
    for (int i = 0;i < xi.size();i++) {
        if (xi[i] > midlle) {
            return false;
        }
        if (tmpsum + xi[i] <= midlle) {
            tmpsum += xi[i];
        }

        else {
            tmparr.push_back(tmpsum);

            tmpsum = 0;
            tmpsum += xi[i];
           
        }
        if (i == xi.size() - 1) {
            tmparr.push_back(tmpsum);
        }
        if (tmparr.size() > k) {
            return false;
        }
    }
    return true;

}

int main() {
    vector<long long> xi;
    cin >> n >> k;
    for (long long i = 0;i < n;i++) {
        cin >> tmp1;
        xi.push_back(tmp1);
    }
    vector <long long>simu(xi);
    sort(simu.begin(), simu.end());
    if (n == k) {
        ans = simu[simu.size() - 1];
    }
    else if(k==1){
        for(int i=0;i<xi.size();i++){
            ans+=xi[i];
        }
    }
    else {


        long long low = 1, top = 2e14, midlle = 0;
        while (low <= top) {
            midlle = (low + top) / 2;
            if (check(midlle, k, xi)) {
                top = midlle - 1;
                ans = midlle;
            }
            else {
                low = midlle + 1;
            }
        }

    }
    cout << ans << "\n";

}