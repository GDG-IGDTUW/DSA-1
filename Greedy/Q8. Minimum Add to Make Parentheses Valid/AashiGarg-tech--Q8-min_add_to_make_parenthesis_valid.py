class Solution(object):
    def minAddToMakeValid(self, s):
        balance = 0
        moves = 0

        for ch in s:
            if ch == '(':
                balance += 1
            else:
                if balance > 0:
                    balance -= 1
                else:
                    moves += 1

        return moves + balance
