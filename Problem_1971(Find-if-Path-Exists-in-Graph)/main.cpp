class DSU{
private:
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n){
        for(int i=0;i<n;i++){
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int findParent(int u){
        if(u == parent[u]){
            return u;
        }
        return parent[u] = findParent(parent[u]);
    }

    void unionByRank(int u, int v){
        int uParent = findParent(u);
        int vParent = findParent(v);
        if(uParent == vParent){
            return;
        }
        if(rank[uParent] > rank[vParent]){
            parent[vParent] = uParent;
        }
        else{
            parent[uParent] = vParent;
            if(rank[uParent] == rank[vParent]){
                rank[vParent]++;
            }
        }
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DSU dsu = DSU(n);
        for(vector<int> &edge: edges){
            int u = edge[0];
            int v = edge[1];
            dsu.unionByRank(u, v);
        }

        return dsu.findParent(source) == dsu.findParent(destination);
    }
};
// PROBLEM:- https://leetcode.com/problems/find-if-path-exists-in-graph/description/
