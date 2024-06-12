class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        map<char, int> mpp;
        
        for(auto it: text){
            mpp[it]++;
        }
        
        int mini = min(mpp['b'], min(mpp['a'], min(mpp['l']/2, min(mpp['o']/2, mpp['n']))));
        return mini;
    }
};