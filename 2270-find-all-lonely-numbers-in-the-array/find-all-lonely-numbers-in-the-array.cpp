class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;
        map<int, int> mpp;
        for(auto it: nums) {
            mpp[it]++;
        }

        for(auto it: mpp) {
            if(it.second == 1 && (mpp.find(it.first-1) == mpp.end()) && (mpp.find(it.first+1) == mpp.end())){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};