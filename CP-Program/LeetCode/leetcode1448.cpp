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
    void dfs(TreeNode* nd,int bg ){
        if(nd==nullptr)return;
        if(nd->val>=bg){
            ans++;
            bg=nd->val;
        }
        dfs(nd->left,bg);
        dfs(nd->right,bg);
    }
    int goodNodes(TreeNode* root) {
        int big=0;
        big=root->val;
        dfs(root,big);
        return ans;
    }
};