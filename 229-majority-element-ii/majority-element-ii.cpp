class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size(), target = n/3;
        vector<int> ans;
        map<int, int> mpp;

        for(auto it: nums) {
            mpp[it]++;
        }

        for(auto it: mpp) {
            if(it.second > target) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};