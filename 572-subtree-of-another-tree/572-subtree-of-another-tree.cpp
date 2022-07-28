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
    bool check(TreeNode* r, TreeNode* s){
        if(r==NULL || s==NULL)
            return (r==s);
        
        if(r->val==s->val){
            if(check(r->left,s->left)&&check(r->right,s->right))
                return true;
        }
            
    
        return false;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(check(root,subRoot))
            return true;
        
        if(root->left!=NULL && isSubtree(root->left, subRoot))
            return true;
        if(root->right!=NULL && isSubtree(root->right, subRoot))
            return true;
        
        return false;
    }
};