typedef pair<int, int> P;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();

        priority_queue<P, vector<P>, greater<P>> pq;
        for(int i=0; i<n; i++){
            pq.push({nums[i], i});
        }
        vector<int> visited(n, false);

        long long ans = 0;
        while(pq.size()>0){
            int val = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            if(visited[idx]){
                continue;
            }
            ans += val;
            visited[idx] = true;
            if(idx-1 >= 0){
                visited[idx-1] = true;
            }
            if(idx+1 < n){
                visited[idx+1] = true;
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/
