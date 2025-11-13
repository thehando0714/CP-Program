class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>info(m,vector<int>(n,0));//0=safe 1=wall 2=guard,guarded=3;
        
        for(int i=0;i<walls.size();i++){
            info[walls[i][0]][walls[i][1]]=1;
            
        }
        
        for(int i=0;i<guards.size();i++){
           info[guards[i][0]][guards[i][1]]=2;
        }
        for(int i=0;i<m;i++){
            bool seen=false;
            for(int j=0;j<n;j++){
                if(info[i][j]==1)seen=false;
                else if(info[i][j]==2)seen=true;
                else if(seen&&info[i][j]==0)info[i][j]=3;
            }
            seen=false;
            for(int j=n-1;j>=0;j--){
                if(info[i][j]==1)seen=false;
                else if(info[i][j]==2)seen=true;
                else if(seen&&info[i][j]==0)info[i][j]=3;
            }
        }
        for (int j = 0; j < n; j++) {
            bool seen = false;
            for (int i = 0; i < m; i++) {
                if (info[i][j] == 1) seen = false;
                else if (info[i][j] == 2) seen = true;
                else if (seen && info[i][j] == 0) info[i][j] = 3;
            }
            seen = false;
            for (int i = m - 1; i >= 0; i--) {
                if (info[i][j] == 1) seen = false;
                else if (info[i][j] == 2) seen = true;
                else if (seen && info[i][j] == 0) info[i][j] = 3;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (info[i][j] == 0) ans++;
        
        return ans;
    }
};