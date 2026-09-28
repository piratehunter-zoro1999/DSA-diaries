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
    int preIdx=0;
    int search(int l,int r,int tar ,vector<int> & in){

        for(int i=l;i<=r;i++){
            if(tar==in[i]){
                return i;
            }
        }
        return -1;
    }

    TreeNode* build (vector<int> &pre,vector<int> &in,int l,int r){

        if(l>r) return NULL;

        TreeNode* root= new TreeNode(pre[preIdx]);
        int mid= search(l,r,pre[preIdx],in);

        preIdx++;

        root->left=build(pre,in,l,mid-1);
        root->right=build(pre,in,mid+1,r);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        

        return build(preorder,inorder,0,inorder.size()-1);
    }
};