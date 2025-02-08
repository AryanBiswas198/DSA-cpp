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
    void inorderTraversal(TreeNode *root, vector<int> &inorder) {
        TreeNode *curr = root;
        while(curr != NULL) {
            if(curr->left == NULL) {
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode *pre = curr->left;
                while(pre->right != NULL && pre->right != curr) {
                    pre = pre->right;
                }
                if(pre->right == NULL) {
                    pre->right = curr;
                    curr = curr->left;
                }
                else{
                    pre->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        
        vector<int> inorder;
        inorderTraversal(root, inorder);
        return inorder[k-1];
    }
};