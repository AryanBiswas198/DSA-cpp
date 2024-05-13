class Solution {
public:
    int f(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp){
        
        if(ind1 == 0 || ind2 == 0){
            return 0;
        }
        
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }
        
        if(s1[ind1-1] == s2[ind2-1]){
            return dp[ind1][ind2] = 1 + f(ind1-1, ind2-1, s1, s2, dp);
        }
        else{
            return dp[ind1][ind2] = max(f(ind1-1, ind2, s1, s2, dp), f(ind1, ind2-1, s1, s2, dp));
        }
    }
    
    int longestPalindromeSubseq(string s) {
        
        // Memoization
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int n = s.size(), m = s2.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        return f(n, m, s, s2, dp);
    }
};