
class Solution {
    repeatLimitedString(s, repeatLimit) {
        let v = new Array(26).fill(0);

        for (let ch of s) {
            v[ch.charCodeAt(0) - 97]++;
        }

        let pq = [];

        function push(item) {
            pq.push(item);

            let i = pq.length - 1;

            while (i > 0) {
                let parent = Math.floor((i - 1) / 2);

                if (pq[parent][0] >= pq[i][0]) break;

                [pq[parent], pq[i]] = [pq[i], pq[parent]];
                i = parent;
            }
        }

        function pop() {
            let top = pq[0];
            let last = pq.pop();

            if (pq.length > 0) {
                pq[0] = last;

                let i = 0;

                while (true) {
                    let left = 2 * i + 1;
                    let right = 2 * i + 2;
                    let largest = i;

                    if (left < pq.length &&
                        pq[left][0] > pq[largest][0]) {
                        largest = left;
                    }

                    if (right < pq.length &&
                        pq[right][0] > pq[largest][0]) {
                        largest = right;
                    }

                    if (largest === i) break;

                    [pq[i], pq[largest]] =
                        [pq[largest], pq[i]];

                    i = largest;
                }
            }

            return top;
        }

        for (let i = 0; i < 26; i++) {
            if (v[i] > 0) {
                push([i, v[i]]);
            }
        }

        let p = [-1, 0];
        let ans = [];

        while (pq.length > 0) {
            let [ch, cnt] = pop();

            if (p[1] > 0) {
                ans.push(String.fromCharCode(ch + 97));

                push(p);

                if (cnt - 1 > 0) {
                    push([ch, cnt - 1]);
                }

                p = [-1, 0];

            } else {
                for (let i = 0; i < repeatLimit && i < cnt; i++) {
                    ans.push(String.fromCharCode(ch + 97));
                }

                if (cnt > repeatLimit) {
                    p = [ch, cnt - repeatLimit];
                }
            }
        }

        return ans.join('');
    }
}
// PROBLEM:- https://leetcode.com/problems/construct-string-with-repeat-limit/description/
