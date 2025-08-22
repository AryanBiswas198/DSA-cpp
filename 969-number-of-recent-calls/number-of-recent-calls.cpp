class RecentCounter {
public:
    vector<int> pings;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        int lower_range = t - 3000, higher_range = t, cnt = 0;
        pings.push_back(t);

        for(auto it: pings) {
            if(it >= lower_range && it <= higher_range) {
                cnt++;
            }
        }
        return cnt;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */