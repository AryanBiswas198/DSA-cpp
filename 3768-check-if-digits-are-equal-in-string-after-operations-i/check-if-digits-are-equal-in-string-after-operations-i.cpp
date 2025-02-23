#include<bits/stdc++.h>
class Solution {
public:
    bool hasSameDigits(string s) {
        while(!s.empty()) {
            int n = s.length();
            if(n == 2) {
                return s[0] == s[1];
            }
            string ans = "";
            for(int i=0; i<n-1; i++) {
                ans += (s[i]-'0' + s[i+1] - '0')%10;
            }
            s = ans;
        }
        return false;
    }
};