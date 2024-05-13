// class Solution {
// public:
//     int f(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp){
        
//         if(ind1 == 0 || ind2 == 0){
//             return 0;
//         }
        
//         if(dp[ind1][ind2] != -1){
//             return dp[ind1][ind2];
//         }
        
//         if(s1[ind1-1] == s2[ind2-1]){
//             return dp[ind1][ind2] = 1 + f(ind1-1, ind2-1, s1, s2, dp);
//         }
//         else{
//             return dp[ind1][ind2] = max(f(ind1-1, ind2, s1, s2, dp), f(ind1, ind2-1, s1, s2, dp));
//         }
//     }
    
//     int minInsertions(string s) {
//         // Memoization
//         string s2 = s;
//         reverse(s2.begin(), s2.end());
        
//         int n = s.size(), m = s2.size();
//         vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
//         return n - f(n, m, s, s2, dp);
//     }
// };


class Solution {
public:
    int minInsertions(string s) {
        // Tabulation 
        string s2 = s;
        reverse(s2.begin(), s2.end());
        
        int n = s.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return n - dp[n][m];
    }
};