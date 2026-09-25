class Solution {
public:
    int reverseDegree(string s) {
        int total = 0, n = s.size();

        for(int i=0; i<n; i++) {
            total += (('z' - s[i] + 1)*(i+1));
        }
        return total;
    }
};