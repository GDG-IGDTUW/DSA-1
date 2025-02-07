class Solution:
    def getFloorAndCeil(self, x: int, arr: list) -> list:
        floor_x = -1
        ceil_x = -1

        for i in arr:
            floor_x = i if i <= x and i > floor_x else floor_x
            ceil_x = i if i >= x and (i < ceil_x or ceil_x == -1) else ceil_x

        return [floor_x, ceil_x]
