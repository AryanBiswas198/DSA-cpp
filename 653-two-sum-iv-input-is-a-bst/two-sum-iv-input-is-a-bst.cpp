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
        
        set<int> st;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            auto sz = q.size();
            while(sz--) {
                TreeNode *front = q.front();
                q.pop();

                int sum = k - front->val;
                if(st.find(sum) != st.end()) {
                    return true;
                }
                st.insert(front->val);

                if(front->left != NULL) {
                    q.push(front->left);
                }

                if(front->right != NULL) {
                    q.push(front->right);
                }
            }
        }
        return false;
    }
};