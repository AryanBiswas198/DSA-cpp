class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int, int> mpp;
        for(auto it: bills) {
            if(it == 5) {
                mpp[it]++;
            }
            else if(it == 10) {
                if(mpp[5] > 0) {
                    mpp[5]--;
                    mpp[it]++;
                }
                else{
                    return false;
                }
            }
            else{
                if(mpp[10] > 0) {
                    if(mpp[5] > 0) {
                        mpp[5]--;
                        mpp[10]--;
                        mpp[it]++;
                    }
                    else{
                        return false;
                    }
                }
                else if(mpp[5] >= 3) {
                    mpp[5] -= 3;
                    mpp[it]++;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};