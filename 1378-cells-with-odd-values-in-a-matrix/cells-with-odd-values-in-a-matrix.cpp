class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        
        vector<vector<int>> arr(n, vector<int>(m, 0));
        stack<pair<int, int>> st;
        int cnt = 0;
        
        for(auto it: indices){
            st.push({it[0], it[1]});
        }
        
        while(!st.empty()){
            auto ele = st.top();
            st.pop();
            
            int row = ele.first, col = ele.second;
            
            for(int i=0; i<m; i++){
                arr[row][i] += 1;
            }
            
            for(int i=0; i<n; i++){
                arr[i][col] += 1;
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] % 2 != 0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};