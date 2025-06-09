// https://leetcode.com/problems/design-twitter/


class Twitter {
    map<int, set<int>> users;
    map<int, vector<pair<int, int>>> tweets;
    int time = 0;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
         tweets[userId].push_back({tweetId, time++});
    }
    
    vector<int> getNewsFeed(int userId) {

        auto cmp1 = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp1)> pq(cmp1);

        vector<int> res;
        auto followers = users[userId];
        followers.insert(userId);
        for(auto& f: followers)
        {
            auto ftweets = tweets[f];
            //cout<<"Uid= "<<userId<<" f = "<<f<< " " <<ftweets.size()<<endl;
            for(int i=ftweets.size()-1; i>=0; i--)
            {
                    pq.push(ftweets[i]);
             }
            
        }
        
        int i=0;
        while(!pq.empty())
        {
            res.push_back(pq.top().first);
            pq.pop();
            i++;
            if(i>=10)
                break;
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
            users[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        users[followerId].erase(followeeId);
    }
};


