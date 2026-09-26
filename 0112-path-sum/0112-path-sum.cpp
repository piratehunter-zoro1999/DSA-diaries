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
    bool check(TreeNode* root,int tar){
        if(root ==NULL){
            return false;
        }
tar-=root->val;
        if(root->left ==NULL && root->right==NULL){
            return tar==0;
        }
        

        return (check(root->left,tar) || check(root->right,tar) );
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return check(root,targetSum);
    }
};