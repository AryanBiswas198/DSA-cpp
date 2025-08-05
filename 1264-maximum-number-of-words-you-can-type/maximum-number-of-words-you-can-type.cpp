class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        
        unordered_map<char, int> mpp;
        for(auto it: brokenLetters) {
            mpp[it]++;
        }

        int i = 0, n = text.size(), cnt = 0;

        while(i < n) {
            if(isspace(text[i])) {
                i++;
                continue;
            }

            bool flag = false;
            while(i < n && isalpha(text[i])) {
                char ch = text[i];
                if(mpp.find(ch) != mpp.end()) {
                    flag = true;
                }
                i++;
            }
            if(flag == false) {
                cnt++;
            }
        }
        return cnt;
    }
};