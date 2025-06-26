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
    void f(TreeNode *root, int lvl, int &maxLevel) {
        if(!root) {
            return ;
        }
        maxLevel = max(lvl, maxLevel);
        f(root->left, lvl+1, maxLevel);
        f(root->right, lvl+1, maxLevel);
    }

    int maxDepth(TreeNode* root) {
        
        if(root == NULL) {
            return 0;
        }
        int maxLevel = 0;
        f(root, 1, maxLevel);
        return maxLevel;
    }
};