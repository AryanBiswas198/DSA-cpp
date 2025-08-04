class Solution {
public:
    bool areNumbersAscending(string s) {
        
        int i = 0, n = s.size(), prevEle = INT_MIN;

        while(i < n) {
            string num = "";
            if(isdigit(s[i])) {
                while(i < n && isdigit(s[i])) {
                    if(isspace(s[i])) {
                        break;
                    }
                    num += s[i++];
                }

                int number = stoi(num);
                if(number <= prevEle) {
                    return false;
                }
                prevEle = number;
            }
            i++;
        }
        return true;
    }
};