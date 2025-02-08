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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int maxWidth = 0;

        while(!q.empty()) {
            auto sz = q.size();
            int mini = INT_MAX, maxi = INT_MIN;
            while(sz--) {
                auto frontEle = q.front();
                q.pop();

                TreeNode *frontNode = frontEle.first;
                int ind = frontEle.second;

                mini = min(mini, ind);
                maxi = max(maxi, ind);

                if(frontNode->left != NULL) {
                    q.push({frontNode->left, (long long)2*ind+1});
                }

                if(frontNode->right != NULL) {
                    q.push({frontNode->right, (long long)2*ind+2});
                }
            }
            maxWidth = max(maxWidth, (maxi-mini+1));
        }
        return maxWidth;
    }
};