class Solution {
public:
    int findMax(vector<int> &nums) {
        int maxi = INT_MIN;
        for(auto it: nums) {
            maxi = max(maxi, it);
        }
        return maxi;
    }

    bool findSmallestDivisor(int mid, vector<int> &nums, int threshold) {
        int sum = 0, n = nums.size();
        for(int i=0; i<n; i++) {
            sum = sum + (ceil((double)nums[i]/mid));
        }
        return sum <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = findMax(nums), ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(findSmallestDivisor(mid, nums, threshold)) {
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};