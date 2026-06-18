class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> mp;
        for(vector<int> &edge: edges){
            int u = edge[0];
            int v = edge[1];
            mp[u]++;
            mp[v]++;
        }
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            if(itr->second == edges.size()){
                return itr->first;
            }
        }
        return -1;
    }
};
// PROBLEM:- https://leetcode.com/problems/find-center-of-star-graph/description/
