class Solution {
public:
    int possibleStringCount(string word) {
        
        char lastLetter;
        int cnt = 1;
        for(auto it: word) {
            if(it != lastLetter) {
                lastLetter = it;
            }
            else{
                cnt++;
            }
        }
        return cnt;
    }
};