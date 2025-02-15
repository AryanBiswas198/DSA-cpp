class Solution {
public:
    void findCombinations(int ind, string digits, string word, string mapping[], vector<string> &ans) {
        if(ind == digits.size()) {
            ans.push_back(word);
            return ;
        }

        int digit = (digits[ind] - '0');
        string value = mapping[digit];

        for(int i=0; i<value.size(); i++) {
            word.push_back(value[i]);
            findCombinations(ind+1, digits, word, mapping, ans);
            word.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        
        if(digits.length() == 0) {
            return {};
        }

        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string word = "";

        vector<string> ans;
        findCombinations(0, digits, word, mapping, ans);
        return ans;
    }
};