class Solution {
public:
    bool isValid(int val, int s, int e){
        if(val<s || val>e){
            return false;
        }
        return true;
    }
    
    bool canMeasureWater(int x, int y, int target) {
        
        int z = x + y;
        int steps[] = {x, -x, y, -y};
        vector<int> vis(z+1, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        
        while(!q.empty()){
            
            int val = q.front();
            q.pop();
            
            if(val == target){
                return true;
            }
            
            for(int i=0; i<4; i++){
                int newVal = val + steps[i];
                if(isValid(newVal, 0, z) && vis[newVal] == 0){
                    q.push(newVal);
                    vis[newVal] = 1;
                }
            }
        }
        return false;
    }
};