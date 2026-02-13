class Solution:
    def wordBreak(self, s, wordDict):
        wordSet = set(wordDict)
        memo = {}

        def dfs(i):
            if i == len(s):
                return [""]

            if i in memo:
                return memo[i]

            res = []

            for word in wordSet:
                if s.startswith(word, i):
                    parts = dfs(i + len(word))
                    for p in parts:
                        if p:
                            res.append(word + " " + p)
                        else:
                            res.append(word)

            memo[i] = res
            return res

        return dfs(0)
