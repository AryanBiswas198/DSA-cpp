// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int s = 1, e = n, mid = 0;
        while(s < e) {
            mid = s + (e-s) / 2;
            bool isBad = isBadVersion(mid);

            if(isBad == false) {
                s = mid + 1;
            }
            else{
                e = mid;
            }
        }
        return s;
    }
};