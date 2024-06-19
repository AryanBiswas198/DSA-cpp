class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        set<char> lowermpp, uppermpp, st;
        int cnt = 0;
        
        for(auto it: word){
            if('a' <= it && it <= 'z'){
                lowermpp.insert(it);
                if(uppermpp.find(toupper(it)) != uppermpp.end() && st.find(it) == st.end()){
                    cnt++;
                    st.insert(it);
                    st.insert(toupper(it));
                }
            }
            else if('A' <= it && it <= 'Z'){
                uppermpp.insert(it);
                if(lowermpp.find(tolower(it)) != lowermpp.end() && st.find(it) == st.end()){
                    cnt++;
                    st.insert(it);
                    st.insert(tolower(it));
                }
            }
        }
        return cnt;
    }
};