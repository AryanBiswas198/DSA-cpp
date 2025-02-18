class Twitter {
public:
    unordered_map<int, set<int>> friends;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int cnt;
    Twitter() {
        cnt = 0;
        friends.empty();
        tweets.empty();
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({cnt++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        int i = 0;

        for(auto it: tweets[userId]) {
            int cnt = it.first, tweetId = it.second;
            pq.push({cnt, tweetId});
        }

        for(auto followeeId: friends[userId]) {
            for(auto it: tweets[followeeId]) {
                int cnt = it.first, tweetId = it.second;
                pq.push({cnt, tweetId});
            }
        }

        while(!pq.empty() && i < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
            i++;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
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