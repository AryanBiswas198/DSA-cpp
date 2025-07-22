class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        unordered_map<int, int> mpp;

        int ans = 0, sum = 0, left = 0, right = 0, n = nums.size();

        for(int right=0; right<n; right++) {
            while(mpp[nums[right]] != 0) {
                mpp[nums[left]]--;
                sum -= nums[left];
                left++;
            }

            mpp[nums[right]]++;
            sum += nums[right];
            ans = max(ans, sum);
        }
        return ans;
    }
};