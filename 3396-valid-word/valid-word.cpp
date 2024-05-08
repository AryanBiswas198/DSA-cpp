class Solution {
public:
    bool isValid(string word) {
        
        int n = word.size();
        if(n < 3){
            return false;
        }
        
        unordered_set<char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        unordered_set<char> consonents;
        
        bool vowelCheck = false, consonentCheck = false;

        
        for(char ch='A'; ch<='Z'; ch++){
            if(vowels.find(ch) == vowels.end()){
                consonents.insert(ch);
                consonents.insert(ch + 32);
            }
        }
        
        for(int i=0; i<n; i++){
            char ch = word[i];
            if(!isalnum(ch)){
                return false;
            }
            
            if(vowels.find(ch) != vowels.end()){
                vowelCheck = true;
            }
            
            if(consonents.find(ch) != consonents.end()){
                consonentCheck = true;
            }
        }
        
        return vowelCheck && consonentCheck;
    }
};