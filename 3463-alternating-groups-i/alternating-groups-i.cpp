class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        
        int n = colors.size(), cnt = 0;
        
        for(int i=0; i<n; i++){
            if(i == 0){
                if(colors[i] != colors[i+1] && colors[i] != colors[n-1]){
                    cnt++;
                }
                continue;
            }
            
            if(i == n-1){
                if(colors[i] != colors[i-1] && colors[i] != colors[0]){
                    cnt++;
                }
                continue;
            }
            
            if(colors[i] != colors[i-1] && colors[i] != colors[i+1]){
                cnt++;
            }
        }
        return cnt;
    }
};