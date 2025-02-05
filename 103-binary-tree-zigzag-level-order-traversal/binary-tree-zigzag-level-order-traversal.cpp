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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(!root) {
            return {};
        }

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int ind = 1;

        while(!q.empty()) {
            int sz = q.size();
            vector<int> level;
            for(int i=0; i<sz; i++) {
                auto front = q.front();
                q.pop();

                level.push_back(front->val);

                if(front->left != NULL) {
                    q.push(front->left);
                }

                if(front->right != NULL) {
                    q.push(front->right);
                }
            }
            if(ind % 2 == 0){
                reverse(level.begin(), level.end());
                ans.push_back(level);
            }
            else{
                ans.push_back(level);
            }
            ind++;
        }   
        return ans;
    }
};