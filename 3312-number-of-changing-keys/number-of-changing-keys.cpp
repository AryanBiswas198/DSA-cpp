class Solution {
public:
    int countKeyChanges(string s) {
        
        int cnt = 0;
        string newStr = "";
        for(auto ch: s) {
            newStr += tolower(ch);
        }

        for(int i=1; i<newStr.size(); i++) {
            if(newStr[i] != newStr[i-1]) {
                cnt++;
            }
        }
        return cnt;
    }
};