class Solution {
public:
    // int f(int ind1, int ind2, string &word1, string &word2, vector<vector<int>> &dp) {
    //     if(ind1 == 0) {
    //         return ind2;
    //     }

    //     if(ind2 == 0) {
    //         return ind1;
    //     }

    //     if(dp[ind1][ind2] != -1) {
    //         return dp[ind1][ind2];
    //     }

    //     if(word1[ind1-1] == word2[ind2-1]) {
    //         return dp[ind1][ind2] = 0 + f(ind1-1, ind2-1, word1, word2, dp);
    //     }
    //     else{
    //         return dp[ind1][ind2] = 1 + min(f(ind1, ind2-1, word1, word2, dp), min(f(ind1-1, ind2, word1, word2, dp), f(ind1-1, ind2-1, word1, word2, dp)));
    //     }
    // }

    int minDistance(string word1, string word2) {
        
        // Tabulation
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=0; i<=m; i++) {
            dp[0][i] = i;
        }

        for(int i=0; i<=n; i++) {
            dp[i][0] = i;
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};