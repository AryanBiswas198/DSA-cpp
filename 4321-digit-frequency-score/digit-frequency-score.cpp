class Solution {
public:
    int digitFrequencyScore(int n) {
        
        int num = n, sum = 0;
        unordered_map<int, int> mpp;

        while(num != 0) {
            int lastd = num % 10;
            mpp[lastd]++;
            num /= 10;
        }

        for(auto it: mpp) {
            int num = it.first, freq = it.second;
            sum += (num * freq);
        }
        return sum;
    }
};