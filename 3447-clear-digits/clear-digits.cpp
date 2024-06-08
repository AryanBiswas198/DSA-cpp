class Solution {
public:
    string clearDigits(string s) {
        
        stack<char> st;
        string ans = "";
        for(auto it: s){
            if('a' <= it && it <= 'z'){
                st.push(it);
            }
            else{
                st.pop();
            }
        }
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};