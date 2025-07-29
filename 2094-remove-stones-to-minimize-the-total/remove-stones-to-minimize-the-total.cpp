class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int> pq;
        for(auto it: piles) {
            pq.push(it);
        }

        while(k--) {
            int num = pq.top();
            pq.pop();
            pq.push((num+1)/2);
        }

        int minSum = 0;
        while(!pq.empty()) {
            minSum += pq.top();
            pq.pop();
        }
        return minSum;
    }
};