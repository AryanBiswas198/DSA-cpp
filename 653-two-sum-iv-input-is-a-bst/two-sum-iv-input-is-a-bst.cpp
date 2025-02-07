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
    bool findTarget(TreeNode* root, int k) {
        
        queue<TreeNode*> q;
        q.push(root);

        set<int> st;
        while(!q.empty()) {

            auto node = q.front();
            q.pop();

            int sum = k - node->val;
            if(st.find(sum) != st.end()) {
                return true;
            }

            st.insert(node->val);
            if(node->left != NULL) {
                q.push(node->left);
            }

            if(node->right != NULL) {
                q.push(node->right);
            }
        }
        return false;
    }
};