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
    void insertBST(TreeNode* &root, int val) {
        if(root == NULL) {
            TreeNode *newNode = new TreeNode(val);
            root = newNode;
            return ;
        }

        if(root->val > val) {
            insertBST(root->left, val);
        }
        else{
            insertBST(root->right, val);
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(root == NULL) {
            TreeNode *newNode = new TreeNode(val);
            return newNode;
        }
        TreeNode *curr = root;
        insertBST(curr, val);
        return root;
    }
};