class Solution:
    def minRectanglesToCoverPoints(self, points: List[List[int]], w: int) -> int:
        x_coords = sorted(set(point[0] for point in points))

        last = -1
        ans = 0

        for x in x_coords:
            if x > last:
                ans += 1
                last = x + w

        return ans
# PROBLEM:- https://leetcode.com/problems/minimum-rectangles-to-cover-points/description/
