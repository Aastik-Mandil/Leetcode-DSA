class Solution {
    typedef pair<int, pair<int,int>> P;
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();

        priority_queue<P, vector<P>, greater<P>> pq; // {total, {i, j}}
        map<pair<int,int>, bool> visited;
        pq.push({nums1[0] + nums2[0], {0, 0}});
        visited[{0, 0}] = true;

        vector<vector<int>> ans;
        while(pq.size() > 0 && ans.size() < k){
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            ans.push_back({nums1[i], nums2[j]});
            pq.pop();
            if(i+1 < n && visited.find({i+1, j}) == visited.end()){
                pq.push({nums1[i+1] + nums2[j], {i+1, j}});
                visited[{i+1, j}] = true;
            }
            if(j+1 < m && visited.find({i, j+1}) == visited.end()){
                pq.push({nums1[i] + nums2[j+1], {i, j+1}});
                visited[{i, j+1}] = true;
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description
