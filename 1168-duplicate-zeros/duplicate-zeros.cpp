class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        
        vector<int> newArr;
        int n = arr.size(), i = 0, cnt = 0;
        
        while(i < n && cnt < n){
            if(arr[i] == 0){
                ++cnt;
                newArr.push_back(0);
                if(cnt < n){
                    newArr.push_back(0); 
                    ++cnt;
                }
            }
            else{
                newArr.push_back(arr[i]);
                cnt++;
            }
            i++;
        }
        
        arr = newArr;
    }
};