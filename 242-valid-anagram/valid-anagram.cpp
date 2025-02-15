class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length()) {
            return false;
        }
        
        unordered_map<int, int> mpp1, mpp2;
        for(auto it: s) {
            mpp1[it]++;
        }

        for(auto it: t) {
            mpp2[it]++;
        }

        for(auto it: s) {
            if(mpp1[it] != mpp2[it]) {
                return false;
            }
        }
        return true;
    }
};