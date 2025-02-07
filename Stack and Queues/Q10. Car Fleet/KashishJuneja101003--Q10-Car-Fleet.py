class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        ans = prev = 0
        for pp, ss in sorted(zip(position, speed), reverse=True): 
            tt = (target - pp)/ss # time to arrive at target 
            if prev < tt: 
                ans += 1
                prev = tt
        return ans 
