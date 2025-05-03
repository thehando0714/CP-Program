#include<bits/stdc++.h>

using namespace std;

int fullmap[100][100];
int bossCurrentX[500][1];
int bossCurrentY[500][1];
int bossMoveX[500][1];
int bossMoveY[500][1];

int trueBomb[100][100];
int alive[500];
int n, m, k;
int ri, ci, si, ti;

int main() {
    cin >> n >> m >> k;
    for (int i = 0;i < k;i++) {
        alive[i] = 1;
        cin >> ri >> ci >> si >> ti;
        bossCurrentX[i][0] = ri;
        bossCurrentY[i][0] = ci;
        bossMoveX[i][0] = si;
        bossMoveY[i][0] = ti;
    }
    bool allDie = false;
    while (!allDie) {
        int gonnaExplode[100][100]{};
        for (int i = 0;i < k;i++) {
            if (alive[i] == 1) {
                trueBomb[bossCurrentX[i][0]][bossCurrentY[i][0]] = 1;
            }
        }
        for (int i = 0;i < k;i++) {
            if (alive[i] == 1) {

                bossCurrentX[i][0] += bossMoveX[i][0];
                bossCurrentY[i][0] += bossMoveY[i][0];
                int tmpx = bossCurrentX[i][0], tmpy = bossCurrentY[i][0];
                if (tmpx > (n-1) || tmpy > (m - 1)|| tmpx < 0 || tmpy < 0) {
                    alive[i] = 0;
                    continue;
                }
               
                if (trueBomb[bossCurrentX[i][0]][bossCurrentY[i][0]] == 1) {
                    trueBomb[bossCurrentX[i][0]][bossCurrentY[i][0]] = 0;
                    gonnaExplode[bossCurrentX[i][0]][bossCurrentY[i][0]] = 1;
                        alive[i] = 0;
                }
                else if (gonnaExplode[bossCurrentX[i][0]][bossCurrentY[i][0]] == 1) {
                    alive[i] = 0;
                }



            }

        }



        for (int i = 0;i < k;i++) {
            if (i == k - 1 && alive[i] == 0) {
                allDie = true;
            }
            if (alive[i] == 1) {
                break;
            }
        }

    }
    int ans = 0;
    for (int i = 0;i < n;i++) {
        for (int p = 0;p < m;p++) {
            if (trueBomb[i][p] == 1) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
