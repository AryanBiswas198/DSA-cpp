class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        
        unordered_map<int, int> mpp;
        long long cnt = 0;
        
        for(auto it: hours){
            cnt += mpp[(24-(it%24))%24];
            mpp[it%24]++;
        }
        
        return cnt;
    }
};