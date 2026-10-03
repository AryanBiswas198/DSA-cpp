class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        
        unordered_map<int, int> mpp;
        for(auto it: nums) {
            mpp[it]++;
        }

        int sum = 0;

        for(auto it: mpp) {
            int val = it.first, cnt = it.second;
            if(cnt % k == 0) {
                sum += (val*cnt);
            }
        }
        return sum;
    }
};