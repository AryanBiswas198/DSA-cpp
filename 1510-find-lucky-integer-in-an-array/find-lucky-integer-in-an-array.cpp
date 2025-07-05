class Solution {
public:
    int findLucky(vector<int>& arr) {
        
        int n = arr.size(), ans = -1;
        unordered_map<int, int> mpp;
        for(auto it: arr) {
            mpp[it]++;
        }

        for(auto it: mpp) {
            int num = it.first, cnt = it.second;
            if(num == cnt) {
                ans = max(ans, num);
            }
        }
        return ans != -1 ? ans : -1;
    }
};