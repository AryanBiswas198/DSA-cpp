class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size(), target = n/2;
        unordered_map<int, int> mpp;

        for(auto it: nums) {
            ++mpp[it];
            if(mpp[it] > target) {
                return it;
            }
        }
        return 0;
    }
};