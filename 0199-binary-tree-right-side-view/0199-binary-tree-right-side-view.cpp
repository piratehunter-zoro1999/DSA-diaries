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
    void  dfs(TreeNode* root,vector<int> &ans,int dep){
        if(root == NULL) return ;

        if(dep == ans.size()){
            ans.push_back(root->val);
        }

        dfs(root->right,ans,dep+1);
        dfs(root->left,ans,dep+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root,ans,0);
        return ans;
    }
};