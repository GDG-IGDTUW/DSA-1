class Solution:
    def generateParenthesis(self, n: int):
        ans = []

        def helper(open_count, close_count, path):
            if close_count == n:
                ans.append("".join(path))
                return

            if open_count < n:
                path.append('(')
                helper(open_count + 1, close_count, path)
                path.pop()

            if close_count < open_count:
                path.append(')')
                helper(open_count, close_count + 1, path)
                path.pop()

        helper(0, 0, [])
        return ans
