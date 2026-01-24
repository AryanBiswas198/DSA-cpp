class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
        unordered_map<int, int> mpp;
        int n = nums.size();
        for(auto it: nums) {
            ++mpp[it];
            if(mpp[it] >= n/2) {
                return it;
            }
        }
        return 0;
    }
};