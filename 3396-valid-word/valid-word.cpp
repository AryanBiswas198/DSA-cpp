class Solution {
public:
    bool isValid(string word) {
        
        int n = word.size();
        if(n < 3) {
            return false;
        }

        bool vowelCheck = false, consonantCheck = false;
        unordered_set<char> vowelMap = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        unordered_set<char> consonantMap;

        for(char ch='A'; ch<='Z'; ch++) {
            if(vowelMap.find(ch) == vowelMap.end()) {
                consonantMap.insert(ch);
                consonantMap.insert(ch+32);
            }
        }

        for(auto it: word) {
            if(!isalnum(it)) {
                return false;
            }
            else if(vowelMap.find(it) != vowelMap.end()) {
                vowelCheck = true;
            }
            else if(consonantMap.find(it) != consonantMap.end()) {
                consonantCheck = true;
            }
        } 

        return vowelCheck && consonantCheck;
    }
};