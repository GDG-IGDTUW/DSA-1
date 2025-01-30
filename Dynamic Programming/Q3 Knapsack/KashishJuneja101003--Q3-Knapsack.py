def knapsack(N, W, weights, values):
    dp = [0] * (W + 1)

    for i in range(N):
        for w in range(W, weights[i] - 1, -1): 
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i])

    return dp[W]


N = 5
W = 5
weights = [1,1,1,1,1]
values = [1000000000,1000000000,1000000000,1000000000,1000000000]

print(knapsack(N, W, weights, values))
