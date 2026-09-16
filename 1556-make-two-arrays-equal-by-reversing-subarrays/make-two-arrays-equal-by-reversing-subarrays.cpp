class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());

        int i = 0;

        for(auto it: target) {
            if(it != arr[i]) {
                return false;    
            }
            i++;
        }
        return true;
    }
};