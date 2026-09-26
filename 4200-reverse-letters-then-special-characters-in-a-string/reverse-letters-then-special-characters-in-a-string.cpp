class Solution {
public:
    bool checkIfChar(char ch) {
        return (ch >= 'a' && ch <= 'z');
    }

    string reverseByType(string s) {
        int n = s.size(), i = 0, j = n-1;
        string res = s;

        while(i <= j) {
            if(checkIfChar(res[i]) && checkIfChar(res[j])) {
                char temp = res[i];
                res[i] = res[j];
                res[j] = temp;
                i++;
                j--;
            }
            else if(checkIfChar(res[i])) {
                j--;
            }
            else {
                i++;
            }
        }

        i = 0, j = n-1;
        while(i <= j) {
            if(!checkIfChar(res[i]) && !checkIfChar(res[j])) {
                char temp = res[i];
                res[i] = res[j];
                res[j] = temp;
                i++;
                j--;
            }
            else if(!checkIfChar(res[i])) {
                j--;
            }
            else{
                i++;
            }
        }
        return res;
    }
};