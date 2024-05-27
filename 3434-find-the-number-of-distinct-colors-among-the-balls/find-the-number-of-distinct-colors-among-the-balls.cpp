class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        
        unordered_map<int, int> mpp; // Tracks colors of ball
        unordered_map<int, int> st; // Tracks total colors of ball
        
        vector<int> ans;
        int q = queries.size();
        
        for(int i=0; i<q; i++){
            int ball = queries[i][0], col = queries[i][1];
            
            // Check if Ball is already colored
            if(mpp.find(ball) != mpp.end()){
                int prevColor = mpp[ball]; // Find prev color of the ball
                
                // check if prevColor cnt is 1, if yes then erase it, else decrement it
                if(st[prevColor] == 1){
                    st.erase(prevColor);
                }
                else{
                    st[prevColor]--;
                }
                
                // Color the ball wid new color
                mpp[ball] = col;
                
                st[col]++; // Increment the new color count
            }
            // If ball is not colored
            else{
                mpp[ball] = col; // Color the ball
                st[col] += 1; //Track the total number of colored item
            }
            // Store the ans, i.e the total balls colored 
            ans.push_back(st.size());
        }
        return ans;
    }
};