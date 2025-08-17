class Twitter {
public:
    long long time = 0;
    unordered_map<int, unordered_set<int>> fol;
    unordered_map<int, vector<pair<long long, int>>> tweets;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<long long, int>> pq;
        vector<int> feed;

        for(auto it: tweets[userId]) {
            long long t = it.first;
            int tweetId = it.second;
            pq.push({t, tweetId});
        }

        for(auto follower: fol[userId]) {
            for(auto it: tweets[follower]) {
                long long t = it.first;
                int tweetId = it.second;
                pq.push({t, tweetId});
            }
        }

        int i = 0;
        while(!pq.empty() && i < 10) {
            auto top = pq.top();
            pq.pop();

            int tweetId = top.second;
            feed.push_back(tweetId);
            i++;
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        fol[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        fol[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */