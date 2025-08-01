class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        int sum = nums[0], maxi = nums[0], n = nums.size();
        for(int i=1; i<n; i++) {
            if(nums[i] > nums[i-1]) {
                sum += nums[i];
            }
            else{
                maxi = max(maxi, sum);
                sum = nums[i];
            }
        }
        maxi = max(maxi, sum);
        return maxi;
    }
};