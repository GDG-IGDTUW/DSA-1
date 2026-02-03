import java.util.*;

class Twitter {

    private static int timeStamp = 0;

    // Tweet structure
    static class Tweet {
        int id;
        int time;

        Tweet(int id, int time) {
            this.id = id;
            this.time = time;
        }
    }

    // user -> set of followees
    private Map<Integer, Set<Integer>> followMap;
    // user -> list of tweets
    private Map<Integer, List<Tweet>> tweetMap;

    public Twitter() {
        followMap = new HashMap<>();
        tweetMap = new HashMap<>();
    }

    public void postTweet(int userId, int tweetId) {
        tweetMap.putIfAbsent(userId, new ArrayList<>());
        tweetMap.get(userId).add(new Tweet(tweetId, timeStamp++));
    }

    public List<Integer> getNewsFeed(int userId) {
        List<Integer> res = new ArrayList<>();

        PriorityQueue<Tweet> pq = new PriorityQueue<>(
            (a, b) -> b.time - a.time
        );

        // Follow self
        followMap.putIfAbsent(userId, new HashSet<>());
        followMap.get(userId).add(userId);

        for (int followee : followMap.get(userId)) {
            List<Tweet> tweets = tweetMap.get(followee);
            if (tweets != null) {
                for (Tweet t : tweets) {
                    pq.offer(t);
                }
            }
        }

        while (!pq.isEmpty() && res.size() < 10) {
            res.add(pq.poll().id);
        }

        return res;
    }

    public void follow(int followerId, int followeeId) {
        followMap.putIfAbsent(followerId, new HashSet<>());
        followMap.get(followerId).add(followeeId);
    }

    public void unfollow(int followerId, int followeeId) {
        if (followMap.containsKey(followerId) && followeeId != followerId) {
            followMap.get(followerId).remove(followeeId);
        }
    }
}
