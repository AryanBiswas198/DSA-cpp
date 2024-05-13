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
    
//     int minDistance(string word1, string word2) {
        
//         // Memoization
//         int n = word1.size(), m = word2.size();
//         vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
//         int lcs = f(n, m, word1, word2, dp);
//         return (n+m) - 2*lcs;
//     }
// };


// class Solution {
// public:
//     int minDistance(string word1, string word2) {
        
//         // Tabulation
//         int n = word1.size(), m = word2.size();
//         vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
//         for(int i=1; i<=n; i++){
//             for(int j=1; j<=m; j++){
//                 if(word1[i-1] == word2[j-1]){
//                     dp[i][j] = 1 + dp[i-1][j-1];
//                 }
//                 else{
//                     dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//                 }
//             }
//         }
        
//         int lcs = dp[n][m];
//         return (n+m) - 2*lcs;
//     }
// };


class Solution {
public:
    int minDistance(string word1, string word2) {
         // Tabulation Space optimisation
        int n = word1.size(), m = word2.size();
        vector<int> dp(m+1, 0);
        
        for(int i=1; i<=n; i++){
            vector<int> temp(m+1, 0);
            for(int j=1; j<=m; j++){
                if(word1[i-1] == word2[j-1]){
                    temp[j] = 1 + dp[j-1];
                }
                else{
                    temp[j] = max(dp[j], temp[j-1]);
                }
            }
            dp = temp;
        }
        
        int lcs = dp[m];
        return (n+m) - 2*lcs;
    }
};