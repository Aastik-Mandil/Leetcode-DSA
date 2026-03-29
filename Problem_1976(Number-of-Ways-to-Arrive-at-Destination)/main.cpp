int mod = 1e9 + 7;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(vector<int> &road: roads){
            int u=road[0];
            int v=road[1];
            int w=road[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<long long> dist(n,LLONG_MAX);
        vector<int> count(n,0);
        priority_queue<pair<long long, int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q; // {time, node}
        q.push({0,0});
        count[0]=1;
        while(q.size()>0){
            long long time=q.top().first;
            int u=q.top().second;
            q.pop();
            for(auto &nbr: adj[u]){
                int v=nbr.first;
                int w=nbr.second;
                if(dist[v] > (time+w)){
                    dist[v]=time+w;
                    q.push({time+w, v});
                    count[v]=count[u];
                }
                else if(dist[v] == (time+w)){
                    count[v]=(count[v]+count[u])%mod;
                }
            }
        }
        return count[n-1]%mod;
    }
};
// PROBLEM:- https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
