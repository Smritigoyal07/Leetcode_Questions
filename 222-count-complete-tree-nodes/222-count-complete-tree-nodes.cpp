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
    int lheight(TreeNode* root){
        int h = 0 ;
        
        while(root){
            h++;
            root = root->left;
        }
        
        return h;
    }
    
    int rheight(TreeNode* root){
        int h = 0 ;
        
        while(root){
            h++;
            root = root->right;
        }
        
        return h;
    }
    
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int lh , rh;
        lh = lheight(root);
        rh = rheight(root);
        
        if(lh==rh)
            return pow(2,lh)-1;
        
        return 1+countNodes(root->left)+countNodes(root->right);
        
    }
};