class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int esum = 0, osum = 0, n = nums.size();
        for(int i=0; i<n; i++) {
            i % 2 == 0 ? esum += nums[i] : osum += nums[i];
        }
        return esum - osum;
    }
};