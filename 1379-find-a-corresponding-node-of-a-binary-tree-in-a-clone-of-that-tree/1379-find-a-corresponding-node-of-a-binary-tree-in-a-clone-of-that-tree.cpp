/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original==NULL)        // if first given is initially null then return 
        {
            return NULL;
        }
        
        if(original == target)    // our aim 
        {
            return cloned;
        }
        
        TreeNode* left = getTargetCopy( original->left , cloned->left , target);      // traverse all left children
        
        if(left != NULL)
        {
            return left;          // if left brings some ans then return else go for right child
        }
        
        TreeNode* right = getTargetCopy( original->right , cloned->right , target);   // traverse all right children
        
        if(right != NULL)
        {
            return right;         // if right brings some ans then return 
        }
        
        return NULL;              // else return NULL
        
    }
};