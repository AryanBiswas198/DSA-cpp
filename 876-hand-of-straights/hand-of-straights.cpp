class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        int n = hand.size();
        
        if(n%groupSize != 0){
            return false;
        }
        
        map<int, int> mpp;
        
        for(auto it: hand){
            mpp[it]++;
        }
        
        while(!mpp.empty()){
            
            int num = mpp.begin()->first;
            
            mpp[num]--;
            if(!mpp[num]){
                mpp.erase(num);
            }
            
            for(int i=1; i<groupSize; i++){
                int ele = num+i;
                
                if(!mpp[ele]){
                    return false;
                }
                else{
                    mpp[ele]--;
                    
                    if(!mpp[ele]){
                        mpp.erase(ele);
                    }
                }
            }
        }
        return true;
    }
};