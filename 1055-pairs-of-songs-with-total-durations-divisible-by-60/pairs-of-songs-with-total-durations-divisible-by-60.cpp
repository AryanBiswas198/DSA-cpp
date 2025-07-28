class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        long long n = time.size(), cnt = 0;
        unordered_map<int, int> mpp;

        for(auto it: time) {
            cnt += mpp[(60-(it%60))%60];
            mpp[it%60]++;
        }
        return cnt;
    }
};