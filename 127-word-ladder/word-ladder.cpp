class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        set<string> st(wordList.begin(), wordList.end());
        queue<pair<int, string>> q;

        q.push({1, beginWord});
        st.erase(beginWord);

        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            int cnt = front.first;
            string str = front.second;

            if(str == endWord) {
                return cnt;
            }

            for(int i=0; i<str.length(); i++) {
                char originalWord = str[i];
                for(char ch='a'; ch<='z'; ch++) {
                    str[i] = ch;
                    if(st.find(str) != st.end()) {
                        q.push({cnt+1, str});
                        st.erase(str);
                    }
                }
                str[i] = originalWord;
            }
        }
        return 0;
    }
};