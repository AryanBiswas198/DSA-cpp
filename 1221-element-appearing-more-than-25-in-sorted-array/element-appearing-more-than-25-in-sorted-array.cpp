class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        int n = arr.size(), target = n/4, cnt = 1;
        if(n == 1) {
            return arr[0];
        }

        for(int i=1; i<n; i++) {
            if(arr[i-1] == arr[i]) {
                cnt++;
                if(cnt > target) {
                    return arr[i];
                }
            }
            else{
                cnt = 1;
            }
        }
        return 0;
    }
};