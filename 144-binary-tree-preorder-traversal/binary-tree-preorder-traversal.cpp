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
        
        // Iterative Solution
        if(!root) {
            return {};
        }

        stack<TreeNode*> st;
        st.push(root);
        vector<int> preorder;

        while(!st.empty()) {
            auto top = st.top();
            st.pop();

            preorder.push_back(top->val);

            if(top->right) {
                st.push(top->right);
            }

            if(top->left) {
                st.push(top->left);
            }
        }
        return preorder;
    }
};