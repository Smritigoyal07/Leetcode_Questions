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
    bool check(TreeNode* root, TreeNode* B ,vector<TreeNode*> &ans ){       
        if(root==NULL)
            return false ;

        ans.push_back(root);

        if(root->val == B->val)
            return true;   

        if(check(root->left,B,ans) || check(root->right,B,ans))
            return true;     

        ans.pop_back();

        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* result;
        
        vector<TreeNode*> ans1;
        vector<TreeNode*> ans2;
        
        check(root,p,ans1);
        check(root,q,ans2);
        
        for(int i =0 ; i < min(ans1.size(),ans2.size()) ; i++){
            if(ans1[i]==ans2[i])
                result = ans1[i];
        }
        
        return result;
    }
    
};