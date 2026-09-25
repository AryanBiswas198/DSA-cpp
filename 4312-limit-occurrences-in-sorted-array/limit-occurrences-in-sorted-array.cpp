class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        
        int n = nums.size(), cnt = 1;
        vector<int> ans;
        ans.push_back(nums[0]);

        for(int i=1; i<n; i++) {
            ++cnt;
            if(nums[i] == nums[i-1] && cnt <= k) {
                ans.push_back(nums[i]);
            }
            else if(nums[i] != nums[i-1]) {
                cnt = 1;
                ans.push_back(nums[i]);
            }
            else{
                continue;
            }
        }
        return ans;
    }
};