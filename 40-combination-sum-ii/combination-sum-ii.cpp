class Solution {
public:
    void f(int ind, vector<int>& candidates, int target, vector<int> temp, vector<vector<int>> &ans) {
        if(target == 0) {
            ans.push_back(temp);
            return ;
        }

        for(int idx=ind; idx<candidates.size(); idx++) {
            if(idx > ind && candidates[idx] == candidates[idx-1]) {
                continue;
            }

            if(candidates[idx] > target) {
                break;
            }

            temp.push_back(candidates[idx]);
            f(idx+1, candidates, target-candidates[idx], temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;

        f(0, candidates, target, temp, ans);
        return ans;
    }
};