class Solution {
public:
    int maxSum(vector<int>& nums) {
        
        unordered_set<int> st;
        sort(nums.begin(), nums.end());

        int n = nums.size(), sum = 0;
        if(nums[n-1] <= 0) {
            return nums[n-1];
        }

        for(auto it: nums) {
            if(it > 0 && st.find(it) == st.end()) {
                st.insert(it);
                sum += it;
            }
        }
        return sum;
    }
};