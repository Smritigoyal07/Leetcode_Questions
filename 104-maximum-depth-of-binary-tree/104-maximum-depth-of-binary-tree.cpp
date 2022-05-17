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
    int maxDepth(TreeNode* root) {
        // using this formula 1 + max of ( left height or right height)
        // +1 for root node 
        
        if(root == NULL)          // NULL condition
        {
            return 0;
        }
        
        int lh = maxDepth(root->left);     // left height 
        int rh = maxDepth(root->right);    // right height 
        
        return 1+max(lh,rh);
        
    }
};