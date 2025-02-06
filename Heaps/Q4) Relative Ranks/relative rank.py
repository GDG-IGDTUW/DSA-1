class Solution:
    def findRelativeRanks(self, score):
        n = len(score)
        M = 0
        for x in score:
            if x > M:
                M = x
        score_idx = [0] * (M + 1)
        for i in range(n):
            score_idx[score[i]] = i + 1

        medals = ["Gold Medal", "Silver Medal", "Bronze Medal"]

        rank = ["" for _ in range(n)]
        place = 1
        for i in range(M, -1, -1):
            if score_idx[i] != 0:
                org_idx = score_idx[i] - 1
                if place < 4:
                    rank[org_idx] = medals[place - 1]
                else:
                    rank[org_idx] = str(place)
                place += 1
        return rank