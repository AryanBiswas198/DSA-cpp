class Solution {
public:
    void findMinMax(int &low, int &high, vector<int> &bloomDay) {
        for(auto it: bloomDay) {
            low = min(low, it);
            high = max(high, it);
        }
    }

    bool isPossible(int day, vector<int> &bloomDay, int m, int k) {

        int n = bloomDay.size(), cnt = 0, bouq = 0;
        for(int i=0; i<n; i++) {
            if(bloomDay[i] <= day) {
                cnt++;
            }
            else{
                bouq += (cnt/k);
                cnt = 0;
            }
        }
        bouq += (cnt/k);
        return bouq >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size(), ans = 0, low = INT_MAX, high = INT_MIN;
        long long val = m * 1ll * k * 1ll;
        if(n < val) {
            return -1;
        }

        findMinMax(low, high, bloomDay);

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossible(mid, bloomDay, m, k)) {
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};