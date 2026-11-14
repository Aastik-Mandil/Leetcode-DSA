using System;
using System.Collections.Generic;

public class Solution {
    public int MinRectanglesToCoverPoints(int[][] points, int w) {
        SortedSet<int> set = new SortedSet<int>();

        foreach (int[] point in points) {
            set.Add(point[0]);
        }

        int last = -1, ans = 0;

        foreach (int x in set) {
            if (x > last) {
                ans++;
                last = x + w;
            }
        }

        return ans;
    }
}
// PROBLEM:- https://leetcode.com/problems/minimum-rectangles-to-cover-points/description/
