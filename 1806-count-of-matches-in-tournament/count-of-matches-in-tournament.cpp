class Solution {
public:
    int numberOfMatches(int n) {
        // IF N teams play and we get only one winner, that means the rest N-1 team lose, so return n-1
        return n-1;
    }
};