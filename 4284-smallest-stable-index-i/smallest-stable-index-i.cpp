class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
        int n = nums.size(), maxi = INT_MIN, mini = INT_MAX;
        vector<int> prefix(n, INT_MIN);
        vector<int> suffix(n, INT_MAX);

        for(int i=0; i<n; i++) {
            maxi = max(nums[i], maxi);
            mini = min(nums[n-i-1], mini);
            prefix[i] = maxi;
            suffix[n-i-1] = mini;
        }

        for(int i=0; i<n; i++) {
            if(prefix[i] - suffix[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};