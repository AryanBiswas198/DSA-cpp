class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
        unordered_map<int, int> mpp1, mpp2;
        for(auto it: target) {
            mpp1[it]++;
        }

        for(auto it: arr) {
            mpp2[it]++;
        }

        for(auto it: mpp1) {
            int num = it.first, cnt = it.second;
            if(cnt != mpp2[num]) {
                return false;
            }
        }
        return true;
    }
};