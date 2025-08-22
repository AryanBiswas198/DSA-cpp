class AuthenticationManager {
public:
    int ttl = 0;
    unordered_map<string, int> mpp;
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mpp[tokenId] = currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        if(mpp.find(tokenId) != mpp.end() && ttl + mpp[tokenId] > currentTime) {
            mpp[tokenId] = currentTime;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int cnt = 0;
        for(auto it: mpp) {
            int tokenTime = it.second;
            if(ttl + tokenTime > currentTime) {
                cnt++;
            }
        }
        return cnt;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */