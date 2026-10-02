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

        bool unionByRank(int u, int v){
            int uParent = findParent(u);
            int vParent = findParent(v);
            if(uParent == vParent){
                return true;
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
            return false;
        }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int n = edges.size();
        DSU dsu = DSU(n);
        for(vector<int> &edge: edges){
            int u = edge[0]-1;
            int v = edge[1]-1;
            bool res = dsu.unionByRank(u, v);
            if(res){
                ans = edge;
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/redundant-connection/description/
