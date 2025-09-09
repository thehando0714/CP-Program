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
    vector<long long>vt;
    long long ans=0;
    
    void dfs(TreeNode* nd,int tS){
        if(nd==nullptr)return;
        vt.push_back(nd->val+vt[vt.size()-1]);
        for(int i=0;i<vt.size()-1;i++){
            if(vt[vt.size()-1]-vt[i]==tS){
                ans++;
            }
        }
        dfs(nd->left,tS);
        dfs(nd->right,tS);
        vt.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        
        vt.push_back(0);
        dfs(root,targetSum);
        return ans;
    }
};