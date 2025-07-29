class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {

        int n = groupSizes.size();
        unordered_map<int, vector<int>> mpp;
        vector<vector<int>> ans;

        for(int i=0; i<n; i++) {
            int grpSize = groupSizes[i];
            mpp[grpSize].push_back(i);
        }

        for(auto [sz, list]: mpp) {
            for(int i=0; i<list.size(); i+=sz) {
                vector<int> group(list.begin() + i, list.begin()+i + sz);
                ans.push_back(group);
            }
        }
        return ans;
    }
};