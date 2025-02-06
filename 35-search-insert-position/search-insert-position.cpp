class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n = nums.size();
        if(target > nums[n-1]) {
            return n;
        }

        int s = 0, e = n-1, ind = -1;

        while(s<=e) {
            int mid = s+(e-s)/2;
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] >= target) {
                e = mid-1;
                ind = mid;
            }
            else{
                s = mid + 1;
            }
        }
        return ind;
    }
};