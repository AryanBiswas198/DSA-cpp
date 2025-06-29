class Solution {
public:
    bool isValid(string s) {
        
        int n = s.size();
        stack<char> st;

        for(int i=0; i<n; i++) {
            char c = s[i];
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else{
                if(st.empty()) {
                    return false;
                }
                if((st.top() == '(' && c == ')') || (st.top() == '[' && c == ']') || (st.top() == '{' && c == '}')) {
                    st.pop();
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return st.size() < 1;
    }
};