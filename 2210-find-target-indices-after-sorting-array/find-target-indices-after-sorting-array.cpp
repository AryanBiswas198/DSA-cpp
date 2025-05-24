class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int i = 0;

        for(auto it: nums) {
            if(it == target) {
                ans.push_back(i);
            }
            i++;
        }
        return ans;
    }
};