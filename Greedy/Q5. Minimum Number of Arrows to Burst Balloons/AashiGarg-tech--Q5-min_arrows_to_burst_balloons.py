class Solution(object):
    def findMinArrowShots(self, points):
        if not points:
            return 0

        points.sort(key=lambda x: x[1])

        arrows = 1
        pos = points[0][1]

        for start, end in points[1:]:
            if start > pos:
                arrows += 1
                pos = end

        return arrows
