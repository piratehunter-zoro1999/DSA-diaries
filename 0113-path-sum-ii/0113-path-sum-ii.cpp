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
    void dfs(vector<vector<int>> &ans,vector<int> temp,TreeNode* root,int tar){
        
        if(root == NULL) return;

        temp.push_back(root->val);
        tar-=root->val;

        if(root->left == NULL && root->right ==NULL && tar==0){
                ans.push_back(temp);
                return;
        }

        dfs(ans,temp,root->left,tar);
        dfs(ans,temp,root->right,tar);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        
        dfs(ans,{},root,targetSum);

        return ans;
    }
};