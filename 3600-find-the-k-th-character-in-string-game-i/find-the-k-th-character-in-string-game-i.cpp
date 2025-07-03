class Solution {
public:
    char kthCharacter(int k) {
        
        string word = "a", prev = word;
        while(word.size() <= k) {
            for(int i=0; i<prev.size(); i++) {
                prev[i] == 'z' ? prev[i] = 'a' : prev[i] = prev[i] + 1;
            }
            word = word + prev;
            prev = word;
        }
        return word[k-1];
    }
};