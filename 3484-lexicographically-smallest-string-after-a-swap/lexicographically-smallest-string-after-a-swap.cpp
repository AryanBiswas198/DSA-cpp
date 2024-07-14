class Solution {
public:
    string getSmallestString(string s) {
        
        int n = s.size();
        for(int i=1; i<n; i++){
            int val1 = int(s[i]), val2 = int(s[i-1]);
            if(((val1%2 != 0 && val2%2 != 0) || (val1%2 == 0 && val2%2 == 0)) && val2 > val1){
                swap(s[i], s[i-1]);
                break;
            }
        }
        return s;
    }
};