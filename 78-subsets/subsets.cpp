class Solution {
public:
    void findSubsets(int ind, vector<int> nums, vector<int> temp, vector<vector<int>> &ans) {
        if(ind == nums.size()) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        findSubsets(ind+1, nums, temp, ans);
        temp.pop_back();
        findSubsets(ind+1, nums, temp, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        findSubsets(0, nums, temp, ans);
        return ans;
    }
};