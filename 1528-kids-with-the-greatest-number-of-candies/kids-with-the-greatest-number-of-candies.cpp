class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int maxi = 0, n = candies.size();
        vector<bool> ans;
        
        for(auto it: candies) {
            maxi = max(maxi, it);
        }

        for(auto it: candies) {
            it + extraCandies >= maxi ? ans.push_back(true) : ans.push_back(false);
        }
        return ans;
    }
};