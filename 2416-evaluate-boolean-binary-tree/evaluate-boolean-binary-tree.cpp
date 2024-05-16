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
    bool f(TreeNode * root){

       if(root->left == NULL && root->right == NULL){
           return root->val;
       }
        
        bool left = f(root->left);
        bool right = f(root->right);
        
        return root->val == 2 ? left | right : left && right;
    }
    
    bool evaluateTree(TreeNode* root) {
        return f(root);
    }
};