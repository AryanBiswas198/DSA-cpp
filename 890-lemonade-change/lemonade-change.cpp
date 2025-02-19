// class Solution {
// public:
//     bool lemonadeChange(vector<int>& bills) {
//         map<int, int> mpp;
//         for(auto it: bills) {
//             if(it == 5) {
//                 mpp[it]++;
//             }
//             else if(it == 10) {
//                 if(mpp[5] > 0) {
//                     mpp[5]--;
//                     mpp[it]++;
//                 }
//                 else{
//                     return false;
//                 }
//             }
//             else{
//                 if(mpp[10] > 0) {
//                     if(mpp[5] > 0) {
//                         mpp[5]--;
//                         mpp[10]--;
//                         mpp[it]++;
//                     }
//                     else{
//                         return false;
//                     }
//                 }
//                 else if(mpp[5] >= 3) {
//                     mpp[5] -= 3;
//                     mpp[it]++;
//                 }
//                 else{
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        // space complexity optimised
        // Instead of map, we'll use variables to track the cnt of each note
        int five = 0, ten = 0, twenty = 0;

        for(auto it: bills) {
            if(it == 5) {
                five++;
            }
            else if(it == 10) {
                if(five > 0) {
                    five--;
                    ten++;
                }
                else{
                    return false;
                }
            }
            else{
                if(ten > 0) {
                    if(five > 0) {
                        ten--;
                        five--;
                        twenty++;
                    }
                    else{
                        return false;
                    }
                }
                else if(five >= 3) {
                    five -= 3;
                    twenty++;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};