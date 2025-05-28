class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if(n <= k && m <= k) {
            return 0;
        }
        else if(n <= k && m > k) {
            long long diff = m - k;
            long long cost = k * diff;
            return cost;
        }
        else if(m <= k && n > k) {
            long long diff = n - k;
            long long cost = k * diff;
            return cost;
        }
        return 0;
    }
};