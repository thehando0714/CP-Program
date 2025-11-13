#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    int t=1;
    while (T--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        vector<vector<int>>a(n,vector(m));
        for(int i=0;i<n;i++){
            for(int k=0;k<m;k++){
                cin>>a[i][j];
            }
        }
        long long bestArea=0,bestCost=0;
        for(int top=0;top<n;;top++){
            vector<long long>colSum(M,0);
            for(int bottom=top;bottom<n;bottom++){
                for(int col=0;col<m;col++){
                    colSum[col]+=a[bottom][col];
                }
                long long sum=0;
                int left=0;
                for(int right=0;right<n;right++){
                    sum+=colSum[right];

                    while (sum>k&&left<=right)
                    {
                        sum-=colSum[left];
                        left++;;
                    }

                    int height=bottom-top+1;
                    int width=right-left+1;
                    long long area=(long long)height*width;

                    if(sum<=k){
                        if(area>bestArea){
                            bestArea=area;
                            bestCost=sum;
                        }
                        else if(area==bestArea&&sum<bestCost){
                            bestCost=sum;
                        }
                    }

                }
            }
        }
        cout << "Case #" << t++ << ": ";
        cout << bestArea << " " << bestCost << "\n";
    }
    
}