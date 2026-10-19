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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
           if(root == NULL) return {};
        
        queue<TreeNode*> q;

        q.push(root);
        stack<vector<int>> qq;
        vector<vector<int>> ans;

        while(!q.empty()){
            int size=q.size();
            

            vector<int> temp;

            while(size--){
                
                TreeNode * curr= q.front();
                temp.push_back(curr->val);
                q.pop();

                if(curr->left !=NULL) q.push(curr->left);
                if(curr->right !=NULL)q.push(curr->right);
            }

            qq.push(temp);
        }

        while(!qq.empty()){
            ans.push_back(qq.top());
            qq.pop();
        }        
      return ans;
    
    
    }
};