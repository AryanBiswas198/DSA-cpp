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
    vector<int> preorderTraversal(TreeNode* root) {
        
        // Morris preorder traversal
        if(root == NULL) {
            return {};
        }

        vector<int> ans;
        TreeNode *curr = root;

        while(curr != NULL) {
            if(curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                ans.push_back(curr->val);
                TreeNode *pre = curr->left;
                while(pre->right != NULL && pre->right != curr) {
                    pre = pre->right;
                }
                pre->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
                curr = curr->right;
            }
        }
        return ans;
    }
};