class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size(), evenSum = 0, oddSum = 0;
        for(int i=0; i<n; i++) {
            i % 2 == 0 ? evenSum += piles[i] : oddSum += piles[i];
        }

        return evenSum >= oddSum ? true : true;
    }
};