import heapq
from collections import defaultdict

class Twitter(object):

    def __init__(self):
        self.time = 0
        self.tweetMap = defaultdict(list)   # userId -> list of (time, tweetId)
        self.followMap = defaultdict(set)   # userId -> set of followees

    def postTweet(self, userId, tweetId):
        self.tweetMap[userId].append((self.time, tweetId))
        self.time += 1

    def getNewsFeed(self, userId):
        res = []
        heap = []

        # User should follow themselves
        self.followMap[userId].add(userId)

        for followee in self.followMap[userId]:
            if followee in self.tweetMap:
                index = len(self.tweetMap[followee]) - 1
                time, tweetId = self.tweetMap[followee][index]
                heapq.heappush(heap, (-time, tweetId, followee, index - 1))

        while heap and len(res) < 10:
            time, tweetId, followee, index = heapq.heappop(heap)
            res.append(tweetId)

            if index >= 0:
                time, tweetId = self.tweetMap[followee][index]
                heapq.heappush(heap, (-time, tweetId, followee, index - 1))

        return res

    def follow(self, followerId, followeeId):
        self.followMap[followerId].add(followeeId)

    def unfollow(self, followerId, followeeId):
        if followeeId in self.followMap[followerId] and followerId != followeeId:
            self.followMap[followerId].remove(followeeId)
