use std::collections::BTreeSet;

impl Solution {
    pub fn min_rectangles_to_cover_points(
        points: Vec<Vec<i32>>,
        w: i32
    ) -> i32 {
        let mut set = BTreeSet::new();

        for point in points.iter() {
            set.insert(point[0]);
        }

        let mut last = -1;
        let mut ans = 0;

        for x in set {
            if x > last {
                ans += 1;
                last = x + w;
            }
        }

        ans
    }
}
// PROBLEM:- https://leetcode.com/problems/minimum-rectangles-to-cover-points/description/
