
class Twitter {
private:
    struct Tweet {
        int tweetId;
        int time;
        Tweet* next;
        Tweet(int id, int t) : tweetId(id), time(t), next(nullptr) {}
    };
    int timer = 0;
    unordered_map<int, Tweet*> tweets;
    unordered_map<int, unordered_set<int>> followers;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        Tweet* t = new Tweet(tweetId, ++timer);
        t->next = tweets[userId];
        tweets[userId] = t;
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweet*> pq;
        if (tweets[userId])
            pq.push(tweets[userId]);
        for (int f : followers[userId]) {
            if (tweets[f])
                pq.push(tweets[f]);
        }
        vector<int> res;
        int i = 0;
        while (!pq.empty() && i < 10) {
            Tweet* t = pq.top();
            res.push_back(t->tweetId);
            pq.pop();
            if (t->next)
                pq.push(t->next);
            i++;
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
