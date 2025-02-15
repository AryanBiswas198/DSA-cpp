class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size() == 1) {
            return strs[0];
        }

        string pref = strs[0];
        int prefLen = pref.length(), n = strs.size();

        for(int i=1; i<n; i++) {
            string word = strs[i];
            while(prefLen > word.length() || pref != word.substr(0, prefLen)) {
                prefLen--;
                if(prefLen == 0) {
                    return "";
                }

                pref = pref.substr(0, prefLen);
            }
        }
        return pref;
    }
};