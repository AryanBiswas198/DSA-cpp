class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        
        sort(prices.begin(), prices.end());
        sort(discounts.begin(), discounts.end());

        int n = prices.size(), m = discounts.size(), i = n-1, j = m-1;
        double ans = 0.0;

        while(i >= 0 && j >= 0) {
            int p = prices[i--], d = discounts[j--];
            ans += double(p*(100 - d)) / 100;
        }

        while(i >= 0) {
            ans += prices[i--];
        }
        return ans;
    }
};