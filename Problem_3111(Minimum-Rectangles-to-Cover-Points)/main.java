import java.util.*;

class Solution {
    public int minRectanglesToCoverPoints(int[][] points, int w) {
        TreeSet<Integer> set = new TreeSet<>();

        for (int[] point : points) {
            set.add(point[0]);
        }

        int last = -1, ans = 0;

        for (int x : set) {
            if (x > last) {
                ans++;
                last = x + w;
            }
        }

        return ans;
    }
}
// PROBLEM:- https://leetcode.com/problems/minimum-rectangles-to-cover-points/description/
