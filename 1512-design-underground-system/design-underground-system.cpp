class UndergroundSystem {
public:
    // mpp is used to store checkIn of a single id with its start station and time
    unordered_map<int, pair<string, int>> mpp;

    // Below is used to store diff times taken by people for a single route
    unordered_map<string, vector<int>> stationMap;

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        if(mpp.find(id) == mpp.end()) {
            mpp[id] = {stationName, t};
        }
    }
    
    void checkOut(int id, string stationName, int t) {
        if(mpp.find(id) != mpp.end()) {
            string fullStationName = mpp[id].first + '#' + stationName;
            int totalTime = t - mpp[id].second;
            stationMap[fullStationName].push_back(totalTime);
            mpp.erase(id);
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string fullStationName = startStation + '#' + endStation;
        double res = 0;
        int totalStations = stationMap[fullStationName].size();

        for(auto it: stationMap[fullStationName]) {
            res += it;
        }
        return res / totalStations;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */