class Solution {
public:
    vector<string> f(int ind, int lastInd, vector<vector<vector<string>>> &dp, vector<string>& words, vector<int>& groups) {
        if(ind == words.size()) {
            return {};
        }

        if(!dp[ind][lastInd+1].empty()) {
            return dp[ind][lastInd+1];
        }

        vector<string> skip = f(ind+1, lastInd, dp, words, groups);

        if(lastInd != groups[ind]) {
            vector<string> take = f(ind+1, groups[ind], dp, words, groups);
            take.insert(take.begin(), words[ind]);
            dp[ind][lastInd+1] = (take.size() > skip.size() ? take : skip);
        }
        else{
            dp[ind][lastInd+1] = skip;
        }
        return dp[ind][lastInd+1];
    }

    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        
        // Memoization Solution
        int n = words.size();
        vector<vector<vector<string>>> dp(n, vector<vector<string>>(n+1));
        return f(0, -1, dp, words, groups);
    }
};