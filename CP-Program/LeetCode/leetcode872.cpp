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
    vector<int>tmp;
    void dfs(TreeNode* nd){
        if(nd==nullptr)return;
        if(nd->left==nullptr&&nd->right==nullptr){
            tmp.push_back(nd->val);
        }
        dfs(nd->left);
        dfs(nd->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1);
        vector<int>v1=tmp;
        tmp.clear();
        dfs(root2);
        if(tmp.size()!=v1.size()){
            return false;
        }
        for(int i=0;i<tmp.size();i++){
            if(tmp[i]!=v1[i]){
                return false;
            }
        }
        return true;
    }
};