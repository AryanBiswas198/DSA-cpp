class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> mpp;

        for(auto it: nums1) {
            int id = it[0], val = it[1];
            mpp[id] += val;
        }

        for(auto it: nums2) {
            int id = it[0], val = it[1];
            mpp[id] += val;
        }

        vector<vector<int>> ans;
        for(auto it: mpp) {
            int id = it.first, val = it.second;
            ans.push_back({id, val});
        }
        return ans;
    }
};