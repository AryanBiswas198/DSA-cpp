class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        // tabulation space optimised
        int n = text1.size(), m = text2.size();
        vector<int> dp(m+1, 0);
        
        for(int i=1; i<=n; i++){
            vector<int> temp(m+1, 0);
            for(int j=1; j<=m; j++){
                if(text1[i-1] == text2[j-1]){
                    temp[j] = 1 + dp[j-1];
                }
                else{
                    temp[j] = max(dp[j], temp[j-1]);   
                }
            }
            dp = temp;
        }
        
        return dp[m];
        // return f(n-1, m-1, text1, text2, dp);
    }
};