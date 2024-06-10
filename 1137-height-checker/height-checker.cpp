class Solution {
public:
    int heightChecker(vector<int>& heights) {
        
        vector<int> temp = heights;
        sort(temp.begin(), temp.end());
        
        int n = heights.size(), cnt = 0;
        
        for(int i=0; i<n; i++){
            if(heights[i] != temp[i]){
                cnt++;
            }
        }
        return cnt;
    }
};