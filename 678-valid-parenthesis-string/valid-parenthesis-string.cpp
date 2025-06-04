class Solution {
public:
    bool checkValidString(string s) {
        
        int n = s.size();
        stack<int> par, star;

        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                par.push(i);
            }
            else if(s[i] == '*') {
                star.push(i);
            }
            else if(s[i] == ')') {
                if(!par.empty()) {
                    par.pop();
                }
                else if(!star.empty()) {
                    star.pop();
                }
                else{
                    return false;
                }
            }
        }

        while(!par.empty() && !star.empty()) {
            if(par.top() < star.top()) {
                par.pop();
                star.pop();
            }
            else{
                return false;
            }
        }
        return par.empty();
    }
};