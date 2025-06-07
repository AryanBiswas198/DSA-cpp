class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> mpp;
        vector<int> ans;
        int n = nums.size(), target = n/3;

        for(auto it: nums) {
            ++mpp[it];
        }

        for(auto it: mpp) {
            if(it.second > target) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};