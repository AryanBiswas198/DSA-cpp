class Solution {
public:
    string reversePrefix(string s, int k) {
        string rev = s;
        reverse(rev.begin(), rev.begin()+k);
        return rev;
    }
};