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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(!root) {
            return {};
        }

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int sz = q.size();
            vector<int> level;
            for(int i=0; i<sz; i++) {
                auto topEle = q.front();
                q.pop();

                level.push_back(topEle->val);

                if(topEle->left) {
                    q.push(topEle->left);
                }

                if(topEle->right) {
                    q.push(topEle->right);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};