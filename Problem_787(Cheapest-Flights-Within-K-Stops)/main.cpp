class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
        for(vector<int> &flight: flights){
            int u=flight[0];
            int v=flight[1];
            int w=flight[2];
            adj[u].push_back({v,w});
        }

        vector<long long int> dist(n,INT_MAX);
        queue<vector<int>> q; // {count,cost,node}
        q.push({k,0,src});
        dist[src]=0;
        while(q.size()>0){
            int count=q.front()[0];
            int cost=q.front()[1];
            int u=q.front()[2];
            q.pop();
            if(count<0){
                continue;
            }
            for(auto &nbr: adj[u]){
                int v=nbr.first;
                int w=nbr.second;
                if(dist[v] > (cost+w)){
                    dist[v]=cost+w;
                    q.push({count-1,cost+w,v});
                }
            }
        }
        return dist[dst]==INT_MAX ? -1 : dist[dst];
    }
};
// PROBLEM:- https://leetcode.com/problems/cheapest-flights-within-k-stops/
