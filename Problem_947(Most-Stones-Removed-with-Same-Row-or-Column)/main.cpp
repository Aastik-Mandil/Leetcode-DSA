class Solution {
    int findParent(int u, vector<int> &parent){
        if(parent[u] == u){
            return u;
        }
        return parent[u] = findParent(parent[u], parent);
    }
    void unionByRank(int u, int v, vector<int> &parent, vector<int> &rank){
        int uParent = findParent(u, parent);
        int vParent = findParent(v, parent);
        if(uParent == vParent){
            return;
        }
        if(rank[uParent] < rank[vParent]){
            parent[uParent] = vParent;
        }
        else{
            parent[vParent] = uParent;
            if(rank[uParent] == rank[vParent]){
                rank[uParent]++;
            }
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }

        for(int i=0;i<n;i++){
            int r1 = stones[i][0];
            int c1 = stones[i][1];
            for(int j=i+1;j<n;j++){
                int r2 = stones[j][0];
                int c2 = stones[j][1];
                if(r1 == r2 || c1 == c2){
                    unionByRank(i, j, parent, rank);
                }
            }
        }

        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(findParent(i, parent));
        }
        return n-st.size();
    }
};
// PROBLEM:- https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
