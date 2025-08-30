class Solution {
public:
    int getLeastFrequentDigit(int n) {
        
        unordered_map<int, int> mpp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int num = n;
        while(num != 0) {
            int lastd = num % 10;
            mpp[lastd]++;
            num /= 10;
        }

        for(auto it: mpp) {
            int num = it.first, cnt = it.second;
            pq.push({cnt, num});
        }

        return pq.top().second;
    }
};