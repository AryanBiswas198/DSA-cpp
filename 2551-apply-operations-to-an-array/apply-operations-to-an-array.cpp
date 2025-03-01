class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int i = 0, j = 0, n = nums.size()-1;

        while(i <= n) {
            if(nums[i] != 0) {
                swap(nums[i], nums[j++]);
            }
            i++;
        }
    }

    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n-1; i++) {
            if(nums[i] == nums[i+1]) {
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }

        moveZeroes(nums);
        return nums;
    }
};