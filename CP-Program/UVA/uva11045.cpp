#include<bits/stdc++.h>
using namespace std;

// === 全域變數與 Dinic 參數定義 ===
const long long INF = 1e18;
const int MAXN = 200; // 節點數量上限 (題目 M<=30, N 也小, 200 很夠用)

// G[u][i]: 存圖的結構
// first: 目標點 v
// second: 反向邊在 G[v] 的索引位置 (rev_idx)
vector<pair<int, int>> G[MAXN]; 

// Cap[u][i]: 對應 G[u][i] 這條邊的「剩餘容量」
// 這裡將容量與圖結構分開存，方便修改
vector<long long> Cap[MAXN];

int level[MAXN]; // BFS 分層圖的深度 (從 source 算起第幾層)
int ptr[MAXN];   // 當前弧優化 (記錄 DFS 遍歷到哪條邊，避免重複掃描)

// === Dinic 核心函數 ===

// DFS: 在分層圖上尋找增廣路 (推流)
// u: 當前點, t: 匯點, pushed: 目前這條路徑上的瓶頸流量
long long dfs(int u, int t, long long pushed){
    if(pushed == 0 || u == t) return pushed; // 沒水了或是到終點了

    // int& i = ptr[u]: 引用 ptr，直接更新遍歷進度 (當前弧優化)
    for(int& i = ptr[u]; i < G[u].size(); i++){
        int v = G[u][i].first;
        int rev_idx = G[u][i].second;
        long long& cap = Cap[u][i];

        // 必須滿足: 1.是下一層的點 2.還有殘餘容量
        if(level[v] != level[u] + 1 || cap == 0) continue;

        // 遞迴往下推流
        long long tr = dfs(v, t, min(pushed, cap));
        
        if (tr == 0) continue; // 這條路推不動

        // 更新正向邊與反向邊容量
        cap -= tr;
        Cap[v][rev_idx] += tr;

        return tr; // 找到一條路就回傳
    }
    return 0;
}

// BFS: 建立分層圖 (計算每個點離起點多遠)
// 回傳: 是否能走到匯點 t
bool bfs(int s, int t, int n){
    fill(level, level + n + 1, -1); // 初始化層數為 -1
    level[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i].first;
            long long cap = Cap[u][i];

            // 只有「有殘餘容量」且「未訪問過」的點才加入
            if (cap > 0 && level[v] == -1) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return level[t] != -1;
}

// Dinic 主入口
long long dinic(int s, int t, int n){
    long long flow = 0;
    // 只要還能建立分層圖 (還有路能走)，就繼續推流
    while(bfs(s, t, n)){
        fill(ptr, ptr + n + 1, 0); // 每次 BFS 後，重置當前弧指標
        while(long long pushed = dfs(s, t, INF)){
            flow += pushed;
        }
    }
    return flow;
}

// 建邊函數 (有向邊版本)
// 建立 u -> v 容量 w，同時建立反向邊 v -> u 容量 0
void add_edge(int u, int v, long long w){
    int idx_u = G[u].size();
    int idx_v = G[v].size();

    G[u].push_back({v, idx_v});
    Cap[u].push_back(w);

    G[v].push_back({u, idx_u});
    Cap[v].push_back(0); // 反向邊容量初始為 0
}

// 初始化函數 (多測資必備)
void init(int n){
    for(int i = 0; i <= n; i++){
        G[i].clear();   // 修正: 加上 ()
        Cap[i].clear(); // 修正: 加上 ()
    }
}

// 輔助函數: 把衣服尺寸轉成對應的節點 ID (1~6)
int sizeToInt(string s){
    if (s == "XXL") return 1;
    if (s == "XL")  return 2;
    if (s == "L")   return 3;
    if (s == "M")   return 4;
    if (s == "S")   return 5;
    if (s == "XS")  return 6;
    return 0;
}

int main(){
    int cases;
    cin >> cases;
    while(cases--){
        int N, M; // N: 衣服總數, M: 志工人數
        cin >> N >> M;

        // === 節點地圖 (Memory Map) ===
        // ID 0: 源點 (Source)
        // ID 1~6: 衣服尺寸 (Sizes)
        // ID 7 ~ 6+M: 志工 (Volunteers)
        // ID 7+M: 匯點 (Sink)
        
        int s = 0;          // 源點 ID
        int t = 7 + M;      // 匯點 ID (修正: m -> M)
        int nodeCnt = t + 1; // 總節點數 (用於 init)
        
        init(nodeCnt);

        // 1. 建立「源點 -> 衣服尺寸」的邊
        // 每種尺寸有 N/6 件
        int capacity = N / 6;
        for(int i = 1; i <= 6; i++){
            add_edge(s, i, capacity);
        }

        // 2. 建立「衣服 -> 志工」以及「志工 -> 匯點」的邊
        for(int i = 1; i <= M; i++){
            string s1, s2;
            cin >> s1 >> s2; // 讀入這位志工想要的兩種尺寸

            int sizeID1 = sizeToInt(s1); // 第一種尺寸的 ID (1~6)
            int sizeID2 = sizeToInt(s2); // 第二種尺寸的 ID (1~6)
            
            // 計算這位志工的專屬 ID (從 7 開始排)
            // i 是 1~M，所以要加上 6 (避開衣服尺寸的 ID)
            int volunteer_id = 6 + i; 

            // 邊: 尺寸 -> 志工 (若匹配則容量 1)
            add_edge(sizeID1, volunteer_id, 1); // 修正變數名稱 mismatch
            add_edge(sizeID2, volunteer_id, 1);
            
            // 邊: 志工 -> 匯點 (每人只能拿 1 件)
            add_edge(volunteer_id, t, 1);       // 修正: T -> t
        }

        // 3. 執行最大流 (注意：要等圖全部建好再跑，所以移出 for 迴圈)
        long long maxMatch = dinic(s, t, nodeCnt);

        // 4. 判斷是否每位志工都有拿到衣服
        if(maxMatch == M){ // 修正: m -> M
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }
    return 0;
}