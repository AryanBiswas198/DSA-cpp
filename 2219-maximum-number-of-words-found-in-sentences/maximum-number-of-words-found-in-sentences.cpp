class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {

        int ans = 0;
        for(auto str: sentences) {
            int wordCnt = 1;
            for(auto ch: str) {
                if(ch == ' ') {
                    wordCnt++;
                }
            }
            ans = max(ans, wordCnt);
        }
        return ans;
    }
};