typedef pair<int, int> P;

class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();
        priority_queue<P, vector<P>> pq; // {y, x}
        for(int i=0; i<n; i++){
            pq.push({y[i], x[i]});
        }
        int a = -1, b = -1, c = -1;
        int ans = 0;
        while(pq.size() > 0){
            int j = pq.top().first;
            int i = pq.top().second;
            pq.pop();
            if(a == -1){
                a = i;
                ans += j;
            }
            else if(b == -1 && i != a){
                b = i;
                ans += j;
            }
            else if(c == -1 && i != a && i != b){
                c = i;
                ans += j;
                return ans;
            }
        }
        return -1;
    }
};
// PROBLEM:- https://leetcode.com/problems/maximize-ysum-by-picking-a-triplet-of-distinct-xvalues/description/
