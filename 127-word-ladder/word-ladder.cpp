class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        st.erase(beginWord);
        q.push({beginWord, 1});

        while(!q.empty()) {
            auto frontEle = q.front();
            q.pop();

            string word = frontEle.first;
            int cnt = frontEle.second;

            if(word == endWord) {
                return cnt;
            }

            for(int i=0; i<word.length(); i++) {
                char originalChar = word[i];
                for(char ch='a'; ch<='z'; ch++) {
                    word[i] = ch;
                    if(st.find(word) != st.end()) {
                        q.push({word, cnt+1});
                        st.erase(word);
                    }
                }
                word[i] = originalChar;
            }
        }
        return 0;
    }
};