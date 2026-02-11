class Solution(object):
    def predictTheWinner(self, nums):
        n = len(nums)
        memo = {}

        def dp(l, r):
            if l == r:
                return nums[l]

            if (l, r) in memo:
                return memo[(l, r)]

            take_left = nums[l] - dp(l + 1, r)
            take_right = nums[r] - dp(l, r - 1)

            memo[(l, r)] = max(take_left, take_right)
            return memo[(l, r)]

        return dp(0, n - 1) >= 0
