class Solution {
public:
    void f(int ind, vector<int>& candidates, int target, vector<int> temp, vector<vector<int>> &ans) {

        if(ind == candidates.size()) {
            if(target == 0) {
                ans.push_back(temp);
            }
            return ;
        }

        if(target == 0) {
            ans.push_back(temp);
            return ;
        }

        f(ind+1, candidates, target, temp, ans);

        if(candidates[ind] <= target) {
            temp.push_back(candidates[ind]);
            f(ind, candidates, target-candidates[ind], temp, ans);
            temp.pop_back();
        }
        return ;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> temp;

        f(0, candidates, target, temp, ans);

        return ans;
    }
};