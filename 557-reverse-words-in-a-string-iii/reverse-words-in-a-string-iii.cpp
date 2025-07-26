class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.size();
        string ans = "", temp = "";

        for(int i=0; i<n; i++) {
            if(s[i] == ' ') {
                string rev = temp;
                reverse(rev.begin(), rev.end());
                ans += rev + ' ';
                temp = "";
            }
            else {
                temp.push_back(s[i]);
            }
        }

        string rev = temp;
        reverse(rev.begin(), rev.end());
        ans += rev;
        return ans;
    }
};