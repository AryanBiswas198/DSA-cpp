class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        
        int i = 1, p = 0, q = 0, n = nums.size();
        while(i < n) {
            if(nums[i] <= nums[i-1]) {
                p = i-1;
                break;
            }
            i++;
        }

        while(i < n) {
            if(nums[i] >= nums[i-1]) {
                q = i-1;
                break;
            }
            i++;
        }

        while(i < n) {
            if(nums[i] <= nums[i-1]) {
                break;
            }
            i++;
        }

        if(i == n && (0 < p) && (p < q) && (q < n-1)) return true;
        return false;
    }
};