class Solution {
public:
    int climbStairs(int n) {
        
        // Tabulation space optimised
        int prev1 = 1, prev2 = 1, curr = 0;
        
        for(int i=2; i<=n; i++){
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};