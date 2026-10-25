typedef pair<int, int> P;

class Solution {
    int getPower(int n){
        if(n == 1){
            return 0;
        }
        if(n%2 == 0){
            return 1 + getPower(n / 2);
        }
        return 1 + getPower((3 * n) + 1);
    }
public:
    int getKth(int lo, int hi, int k) {
        // store into max-heap with max size k
        priority_queue<P, vector<P>> pq; // {powerCount, val}
        for(int i=lo; i<=hi; i++){
            pq.push({getPower(i), i});
            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top().second;
    }
};
// PROBLEM:- https://leetcode.com/problems/sort-integers-by-the-power-value/description/
