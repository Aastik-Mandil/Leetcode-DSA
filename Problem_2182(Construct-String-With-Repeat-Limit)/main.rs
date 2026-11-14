use std::collections::BinaryHeap;

impl Solution {
    pub fn repeat_limited_string(
        s: String,
        repeat_limit: i32
    ) -> String {

        let mut v = [0; 26];

        for ch in s.chars() {
            v[(ch as usize) - ('a' as usize)] += 1;
        }

        let mut pq: BinaryHeap<(char, i32)> = BinaryHeap::new();

        for i in 0..26 {
            if v[i] > 0 {
                pq.push(((b'a' + i as u8) as char, v[i]));
            }
        }

        let mut p = ('#', 0);
        let mut ans = String::new();

        while let Some((ch, cnt)) = pq.pop() {

            if p.1 > 0 {
                ans.push(ch);

                pq.push(p);

                if cnt - 1 > 0 {
                    pq.push((ch, cnt - 1));
                }

                p = ('#', 0);

            } else {
                for _ in 0..repeat_limit.min(cnt) {
                    ans.push(ch);
                }

                if cnt > repeat_limit {
                    p = (ch, cnt - repeat_limit);
                }
            }
        }

        ans
    }
}
// PROBLEM:- https://leetcode.com/problems/construct-string-with-repeat-limit/description/
