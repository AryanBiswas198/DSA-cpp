class Solution {
public:
    char shift(char ch, char num) {
        return ch + (num - '0');
    }

    string replaceDigits(string s) {
        
        string ans = "";
        int n = s.size();

        for(int i=0; i<n; i++) {
            if(i % 2 == 0) {
                ans += s[i];
            }
            else{
                char word = shift(s[i-1], s[i]);
                ans += word;
            }
        }
        return ans;
    }
};