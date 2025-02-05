class Solution {
public:
    void findSubsets(int ind, vector<int> nums, vector<int> temp, set<vector<int>> &st) {
        if(ind == -1) {
            sort(temp.begin(), temp.end());
            st.insert(temp);
            return ;
        }

        temp.push_back(nums[ind]);
        findSubsets(ind-1, nums, temp, st);
        temp.pop_back();
        findSubsets(ind-1, nums, temp, st);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        set<vector<int>> st;
        findSubsets(nums.size()-1, nums, temp, st);
        vector<vector<int>> ans(st.begin(), st.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};