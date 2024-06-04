class Solution {
public:
    int longestPalindrome(string s) {
        
        if(s.size() == 1){
            return 1;
        }
        
        unordered_map<char, int> mpp;
        for(auto it: s){
            mpp[it]++;
        }
        
        int oddCount = 0;
        
        for(auto it: mpp){
            if(it.second % 2 != 0){
                oddCount++;
            }
        }
        
        if(oddCount > 1){
            return s.size() - oddCount + 1;
        }
        return s.size();
    }
};