class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int evenSum = 0;
        vector<int> ans;
        
        for(auto it: nums) {
            if(it % 2 == 0) {
                evenSum += it;
            }
        }

        for(auto it: queries) {
            int val = it[0], index = it[1];
            if(nums[index] % 2 == 0) {
                evenSum -= nums[index];
            }
            nums[index] += val;
            if(nums[index] % 2 == 0) {
                evenSum += nums[index];
            }
            ans.push_back(evenSum);
        }
        return ans;
    }
};