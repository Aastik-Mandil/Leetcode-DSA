class Solution {
    minRectanglesToCoverPoints(points, w) {
        let set = new Set();

        for (let point of points) {
            set.add(point[0]);
        }

        let xCoords = [...set].sort((a, b) => a - b);

        let last = -1, ans = 0;

        for (let x of xCoords) {
            if (x > last) {
                ans++;
                last = x + w;
            }
        }

        return ans;
    }
}
// PROBLEM:- https://leetcode.com/problems/minimum-rectangles-to-cover-points/description/
