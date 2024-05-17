// class Solution {
// public:
//     int f(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp){
        
//         if(ind1 == 0){
//             return ind2;
//         }
        
//         if(ind2 == 0){
//             return ind1;
//         }
        
//         if(dp[ind1][ind2] != -1){
//             return dp[ind1][ind2];
//         }
        
//         if(s1[ind1-1] == s2[ind2-1]){
//             return dp[ind1][ind2] = 0 + f(ind1-1, ind2-1, s1, s2, dp);
//         }
//         else{
//             return dp[ind1][ind2] = 1 + min(f(ind1, ind2-1, s1, s2, dp), min(f(ind1-1, ind2, s1, s2, dp), f(ind1-1, ind2-1, s1, s2, dp)));
//         }
//     }
    
//     int minDistance(string word1, string word2) {
        
//         // Memoization
//         int n = word1.size(), m = word2.size();
//         vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
//         return f(n, m, word1, word2, dp);
//     }
// };


// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         // Tabulation
        
//         int n = word1.size(), m = word2.size();
//         vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
//         for(int i=0; i<=m; i++){
//             dp[0][i] = i;
//         }
        
//         for(int i=0; i<=n; i++){
//             dp[i][0] = i;
//         }
        
//         for(int i=1; i<=n; i++){
//             for(int j=1; j<=m; j++){
//                 if(word1[i-1] == word2[j-1]){
//                     dp[i][j] = dp[i-1][j-1];
//                 }
//                 else{
//                     dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
//                 }
//             }
//         }
//         return dp[n][m];
//     }
// };


class Solution {
public:
    int minDistance(string word1, string word2) {
        // Tabulation - space optimisation
        
        int n = word1.size(), m = word2.size();
        vector<int> dp(m+1, 0);
        
        for(int i=0; i<=m; i++){
            dp[i] = i;
        }
        
        for(int i=1; i<=n; i++){
            vector<int> temp(m+1, 0);
            temp[0] = i;
            for(int j=1; j<=m; j++){
                if(word1[i-1] == word2[j-1]){
                    temp[j] = dp[j-1];
                }
                else{
                    temp[j] = 1 + min(dp[j], min(temp[j-1], dp[j-1]));
                }
            }
            dp = temp;
        }
        return dp[m];
    }
};