class Solution {
public:
    string reformat(string s) {
        
        string str = "", num = "", ans = "";
        for(auto it: s) {
            if(it >= 'a' && it <= 'z') {
                str += it;
            }
            else{
                num += it;
            }
        }

        int n = str.size(), m = num.size();
        if(abs(n-m) > 1) {
            return "";
        }

        int i = 0, j = 0;
        while(i < n && j < m) {
            if(n > m) {
                ans += str[i++];
                ans += num[j++];
            }
            else{
                ans += num[j++];
                ans += str[i++];
            }
        }

        while(i < n) {
            ans += str[i++];
        }

        while(j < m) {
            ans += num[j++];
        }
        return ans;
    }
};