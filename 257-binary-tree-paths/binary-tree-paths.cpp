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
    void f(TreeNode *root, vector<string> &ans, string temp) {
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(temp);
            return ;
        }

        if(root->left != NULL) {
            f(root->left, ans, temp+"->"+to_string(root->left->val));   
        }

        if(root->right != NULL) {
            f(root->right, ans, temp+"->"+to_string(root->right->val));
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> ans;
        string temp = to_string(root->val);

        f(root, ans, temp);
        return ans;
    }
};