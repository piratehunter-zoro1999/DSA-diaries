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
    
 
   
    bool check(TreeNode* root,int idx,int h){

        int st =0;
        int end=(1<<h)-1;

        TreeNode* curr=root;

        for(int lvl=0 ;lvl<h;lvl++){
          int mid = st + (end-st)/2;

          if(mid >= idx){
              curr=curr->left;
              end=mid;
          }else{
            curr=curr->right;
              st=mid+1;
          };

          if(curr==NULL) return false;
        }
      return true;
    }

    int countNodes(TreeNode* root) {
        
        if(root == NULL) return 0;

        int h=0;

        TreeNode* curr=root;
        

        while(curr->left){
            
            h++;
            curr=curr->left;
            
        }

        int upperNodes=(1 << h)-1;

        
        

        int left = 0;
        int right = (1 << h)-1;

        while(left<=right){
            int mid = left + (right-left)/2;

            if(check(root,mid,h)){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }

        return upperNodes +left;
      
    }
};