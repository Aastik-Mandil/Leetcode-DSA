
import java.util.*;

class Solution {
    public String repeatLimitedString(String s, int repeatLimit) {
        int[] v = new int[26];

        for (char ch : s.toCharArray()) {
            v[ch - 'a']++;
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>(
            (a, b) -> b[0] - a[0]
        );

        for (int i = 0; i < 26; i++) {
            if (v[i] > 0) {
                pq.offer(new int[]{i, v[i]});
            }
        }

        int[] p = {-1, 0};
        StringBuilder ans = new StringBuilder();

        while (!pq.isEmpty()) {
            int[] top = pq.poll();

            int ch = top[0];
            int cnt = top[1];

            if (p[1] > 0) {
                ans.append((char)(ch + 'a'));

                pq.offer(p);

                if (cnt - 1 > 0) {
                    pq.offer(new int[]{ch, cnt - 1});
                }

                p = new int[]{-1, 0};
            } else {
                for (int i = 0; i < repeatLimit && i < cnt; i++) {
                    ans.append((char)(ch + 'a'));
                }

                if (cnt > repeatLimit) {
                    p = new int[]{ch, cnt - repeatLimit};
                }
            }
        }

        return ans.toString();
    }
}
// PROBLEM:- https://leetcode.com/problems/construct-string-with-repeat-limit/description/
