class Solution {
public:
    string reverseWords(string s) {
        
        stack<string> st;
        int n = s.length();
        string word = "";

        for(int i=0; i<n; i++) {
            char ch = s[i];
            if(ch == ' ') {
                if(word.length() > 0) {
                    word += ' ';
                    st.push(word);
                    word = "";
                }
                continue;
            }

            word += ch;
        }

        if(word.length() > 0) {
            word += ' ';
            st.push(word);
        }

        string ans = "";
        while(!st.empty()) {
            auto top = st.top();
            st.pop();
            ans += top;
        }
        return string(ans.begin(), ans.end() - 1);
    }
};