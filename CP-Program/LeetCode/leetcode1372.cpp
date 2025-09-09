/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    void dfs(TreeNode* nd,int dep,int status){//sta 0 left 1 right -1 root
        if(nd==nullptr)return;
        ans=max(dep,ans);
        int tmp=dep+1;
        if(status==-1){
            dfs(nd->left,1,0);
            dfs(nd->right,1,1);
        }
        else if(status==0){
            dfs(nd->left,1,0);
            dfs(nd->right,tmp,1);
        }
        else if(status==1){
            dfs(nd->left,tmp,0);
            dfs(nd->right,1,1);
        }
        
    }
    int longestZigZag(TreeNode* root) {
        dfs(root,0,-1);
        return ans;
    }
};