class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        
        int s1 = 0, s2 = 0, s3 = 0;
        
        for(auto it: firstWord){
            s1 = (s1*10) + it - 'a';
        }
        
        for(auto it: secondWord){
            s2 = (s2*10) + it - 'a';
        }
        
        for(auto it: targetWord){
            s3 = (s3*10) + it - 'a';
        }
        
        return s1 + s2 == s3;
    }
};