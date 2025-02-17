class Solution {
public:
    void findMaxAndSum(int &low, int &high, vector<int> &weights) {
        for(auto it: weights) {
            low = max(low, it);
            high += it;
        }
    }

    bool isPossible(int load, vector<int> &weights, int days) {
        int wt = 0, dayCnt = 1, n = weights.size();
        for(int i=0; i<n; i++) {
            if(wt + weights[i] <= load) {
                wt += weights[i];
            }
            else{
                dayCnt++;
                wt = weights[i];
            }
        }
        return dayCnt <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0, high = 0, n = weights.size(), ans = 0;
        findMaxAndSum(low, high, weights);

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossible(mid, weights, days)) {
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