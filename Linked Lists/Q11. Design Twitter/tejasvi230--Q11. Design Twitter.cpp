class Twitter {
public:
    Twitter() {}
    int count = 0;
    unordered_map<int,vector<pair<int,int>>>m;
    map<pair<int,int>,int>m1;
    void postTweet(int userId, int tweetId) {
        m[userId].push_back({count,tweetId});
        count++;
    }
    
    vector<int> getNewsFeed(int userId) {
        unordered_set<int> v;
        vector<pair<int,int>>v1;
        vector<int>ans;
        v.insert(userId);
        for(auto i:m1){
            if(i.first.first == userId && i.second>0) v.insert(i.first.second);
        }
        for(auto i:v){
            v1.insert(v1.end(),m[i].begin(),m[i].end());
        }
        sort(v1.rbegin(),v1.rend());
        for(auto i:v1){
            if (ans.size() == 10) break;
            ans.push_back(i.second);
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        m1[{followerId,followeeId}]++;
    }

    void unfollow(int followerId, int followeeId) {
        if(m1[{followerId,followeeId}]) m1[{followerId,followeeId}]--;
    }
};
