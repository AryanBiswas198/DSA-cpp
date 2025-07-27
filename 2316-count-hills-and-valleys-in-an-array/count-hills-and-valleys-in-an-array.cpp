class Solution {
public:
    int countHillValley(vector<int>& nums) {
        
        int n = nums.size(), cnt = 0, i = 1;

        while(i < n-1) {
            int j = i;

            while(j < n-1 && nums[i] == nums[j]) {
                j++;
            }

            if((nums[i] > nums[i-1] && nums[i] > nums[j]) || (nums[i] < nums[i-1] && nums[i] < nums[j])) {
                cnt++;
            }

            i = j;
        }
        return cnt;
    }
};