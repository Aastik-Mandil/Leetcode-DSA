using System;
using System.Collections.Generic;

public class Solution {
    public string RepeatLimitedString(string s, int repeatLimit) {

        int[] v = new int[26];

        foreach (char ch in s) {
            v[ch - 'a']++;
        }

        var pq = new PriorityQueue<(int ch, int cnt), int>();

        for (int i = 0; i < 26; i++) {
            if (v[i] > 0) {
                pq.Enqueue((i, v[i]), -i);
            }
        }

        (int ch, int cnt) p = (-1, 0);

        System.Text.StringBuilder ans =
            new System.Text.StringBuilder();

        while (pq.Count > 0) {

            var top = pq.Dequeue();

            int ch = top.ch;
            int cnt = top.cnt;

            if (p.cnt > 0) {
                ans.Append((char)(ch + 'a'));

                pq.Enqueue(p, -p.ch);

                if (cnt - 1 > 0) {
                    pq.Enqueue((ch, cnt - 1), -ch);
                }

                p = (-1, 0);

            } else {
                for (int i = 0; i < repeatLimit && i < cnt; i++) {
                    ans.Append((char)(ch + 'a'));
                }

                if (cnt > repeatLimit) {
                    p = (ch, cnt - repeatLimit);
                }
            }
        }

        return ans.ToString();
    }
}
// PROBLEM:- https://leetcode.com/problems/construct-string-with-repeat-limit/description/
