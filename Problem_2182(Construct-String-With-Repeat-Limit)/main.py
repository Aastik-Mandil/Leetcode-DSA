import heapq

class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        v = [0] * 26

        for ch in s:
            v[ord(ch) - ord('a')] += 1

        pq = []

        for i in range(26):
            if v[i] > 0:
                heapq.heappush(pq, (-i, v[i]))

        p = (-1, 0)
        ans = []

        while pq:
            ch, cnt = heapq.heappop(pq)
            ch = -ch

            if p[1] > 0:
                ans.append(chr(ch + ord('a')))

                heapq.heappush(pq, p)

                if cnt - 1 > 0:
                    heapq.heappush(pq, (-ch, cnt - 1))

                p = (-1, 0)

            else:
                for i in range(min(repeatLimit, cnt)):
                    ans.append(chr(ch + ord('a')))

                if cnt > repeatLimit:
                    p = (-ch, cnt - repeatLimit)

        return ''.join(ans)

# PROBLEM:- https://leetcode.com/problems/construct-string-with-repeat-limit/description/
