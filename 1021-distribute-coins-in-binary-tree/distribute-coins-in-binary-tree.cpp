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
    int f(TreeNode *root, int &moves){
        if(root == NULL){
            return 0;
        }
        
        int left = f(root->left, moves);
        int right = f(root->right, moves);
        
        moves += abs(left) + abs(right);
        
        return root->val + left + right - 1;
    }
    
    int distributeCoins(TreeNode* root) {
        
        // Read Notes for explaination
        int moves = 0;
        int k = f(root, moves);
        
        return moves;
    }
};