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
    int findMaxPathSum(TreeNode *root, int &maxSum) {
        if(root == NULL) {
            return 0;
        }

        int left = max(0, findMaxPathSum(root->left, maxSum));
        int right = max(0, findMaxPathSum(root->right, maxSum));

        maxSum = max(maxSum, (left+right+root->val));

        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        
        int maxSum = INT_MIN;
        int ans = findMaxPathSum(root, maxSum);
        return maxSum;
    }
};