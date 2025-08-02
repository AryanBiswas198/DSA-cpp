class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        
        long long sum = 0, n = s.size();
        vector<int> suffix(n, 0);

        for(int i=n-1; i>=0; i--) {
            sum += shifts[i];
            suffix[i] = sum % 26;
        }

        for(int i=0; i<s.size(); i++) {
            int newChar = (s[i] - 'a' + suffix[i]);
            char newWord = (newChar%26) + 'a';
            // s[i] = 'a' + (s[i] - 'a' + suffix[i]) % 26;
            s[i] = newWord;
        }
        return s;
    }
};