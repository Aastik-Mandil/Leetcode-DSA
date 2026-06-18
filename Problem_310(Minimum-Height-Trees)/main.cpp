class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // if(n == 1){
        //     return {0};
        // }
        vector<vector<int>> adj(n, vector<int>());
        vector<int> degree(n, 0);
        for(vector<int> &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            degree[u]++;
            degree[v]++;
        }

        queue<int> q;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(degree[i] <= 1){
                q.push(i);
            }
        }
        while(q.size()>0){
            ans.clear();
            int size = q.size();
            while(size>0){
                int node = q.front();
                ans.push_back(node);
                q.pop();
                for(int &nbr: adj[node]){
                    if(degree[nbr] <= 1){
                        continue;
                    }
                    degree[nbr]--;
                    if(degree[nbr] <= 1){
                        q.push(nbr);
                    }
                }
                size--;
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/minimum-height-trees/description/
