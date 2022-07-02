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
    int height(TreeNode * root , int& MaxSum){
        if(root == NULL){
            return 0;
        }
        
        int lh = max(0,height(root->left  , MaxSum));
        int rh = max(0,height(root->right , MaxSum));
        
        MaxSum = max(MaxSum , lh+rh+root->val);
        
        return root->val+max(lh,rh);
        
        
    }
    
    int maxPathSum(TreeNode* root) {
        int MaxSum = INT_MIN ;
        height(root,MaxSum);
            
        return MaxSum;
    
    }
};