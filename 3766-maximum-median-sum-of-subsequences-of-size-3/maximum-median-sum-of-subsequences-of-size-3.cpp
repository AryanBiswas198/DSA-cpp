class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {

        long long sum = 0;
        int n = nums.size(), left = 0, right = n-2;
        
        sort(nums.begin(), nums.end());

        while(left <= right) {
            sum += nums[right];
            left++;
            right-=2;
        }
        return sum;
    }
};