#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<string> map;
//vector<vector<bool>> used;
bool used[1000][1000];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// BFS 函數
void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    used[x][y] = true;

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (int d = 0; d < 4; ++d) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !used[nx][ny] && map[nx][ny] == '.') {
                used[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    
    map.resize(n);
   // used.resize(n, vector<bool>(m, false));

    // 讀入地圖
    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }

    int rooms = 0;

    // 遍歷整張地圖
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == '.' && !used[i][j]) {
                rooms++;
                bfs(i, j);
            }
        }
    }

    cout << rooms << endl;
    return 0;
}
