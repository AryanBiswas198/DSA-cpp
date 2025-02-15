class Solution {
public:
    string largestOddNumber(string num) {
        
        int n = num.size(), l = 0;
        for(int i=n-1; i>=0; i--) {
            if((num[i] - '0') % 2 != 0) {
                break;
            }
            l++;
        }

        return string(num.begin(), num.end() - l);
    }
};