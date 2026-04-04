class Solution {
    int findParent(int u, vector<int> &parent){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=findParent(parent[u], parent);
    }
    bool unionByRank(int u, int v, vector<int> &parent, vector<int> &rank){
        int uParent = findParent(u,parent);
        int vParent = findParent(v,parent);
        if(parent[uParent] == parent[vParent]){
            return true;
        }
        if(rank[uParent]<rank[vParent]){
            parent[uParent] = vParent;
        }
        else{
            parent[vParent] = uParent;
            if(rank[uParent]==rank[vParent]){
                rank[uParent]++;
            }
        }
        return false;
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n);
        vector<int> rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        int count=0;
        for(vector<int> &conn: connections){
            int u=conn[0];
            int v=conn[1];
            bool flag = unionByRank(u,v,parent,rank);
            if(flag){
                count++;
            }
        }

        unordered_set<int> distinctParent;
        for(int i=0;i<n;i++){
            distinctParent.insert(findParent(i,parent));
        }

        if(count >= (distinctParent.size()-1)){
            return distinctParent.size()-1;
        }
        return -1;
    }
};
// PROBLEM:- https://leetcode.com/problems/number-of-operations-to-make-network-connected/
