class Solution {
public:
    int findPermutationDifference(string s, string t) {
        
        map<char, int> mpp;
        int sum = 0;
        
        for(int i=0; i<t.size(); i++){
            mpp[t[i]] = i;
        }
        
        for(int i=0; i<s.size(); i++){
            sum += abs(i - mpp[s[i]]);
        }
        return sum;
    }
};