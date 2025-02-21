class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Tabulation - space optimised
        int n = prices.size();
        vector<int> prev1(2, 0);
        vector<int> prev2(2, 0);

        for(int i=n-1; i>=0; i--) {
            vector<int> curr(2, 0);
            for(int buy=0; buy<=1; buy++) {
                if(buy == 0) {
                    int notPick = prev1[buy];
                    int pick = -prices[i] + prev1[buy+1];

                    curr[buy] = max(pick, notPick);
                }
                else{
                    int notPick = prev1[buy];
                    int pick = prices[i] + prev2[buy-1];

                    curr[buy] = max(pick, notPick);
                }
            }
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1[0];
    }
};