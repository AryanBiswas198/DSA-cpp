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
    int checkBalance(TreeNode *root) {
        if(root == NULL) {
            return 0;
        }

        int left = checkBalance(root->left);
        if(left == -1) {
            return -1;
        }

        int right = checkBalance(root->right);
        if(right == -1) {
            return -1;
        }

        if(abs(left - right) > 1) {
            return -1;
        }

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        
        if(root == NULL) {
            return true;
        }

        return checkBalance(root) != -1;
    }
};