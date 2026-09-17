class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        
        vector<int> ans = nums;
        unordered_map<int, int> mpp;

        for(int i=0; i<nums.size(); i++) {
            mpp[nums[i]] = i;
        }

        for(auto it: operations) {
            int oldVal = it[0], newVal = it[1];
            int oldInd = mpp[oldVal];

            ans[oldInd] = newVal;
            mpp[newVal] = oldInd;
        }
        return ans;
    }
};