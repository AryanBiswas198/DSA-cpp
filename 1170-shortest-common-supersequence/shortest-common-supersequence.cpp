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
    
    string shortestCommonSupersequence(string str1, string str2) {
        
        // Memoization
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        int lcs = f(n, m, str1, str2, dp);
        int i = n, j = m;
        
        string ans = "";
        
        while(i > 0 && j > 0){
            if(str1[i-1] == str2[j-1]){
                ans += str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                ans += str1[i-1];
                i--;
            }
            else{
                ans += str2[j-1];
                j--;
            }
        }
        
        while(i > 0){
            ans += str1[i-1];
            i--;
        }
        
        while(j > 0){
            ans += str2[j-1];
            j--;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};