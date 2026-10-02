class DSU{
    private:
        vector<int> parent;
        vector<int> rank;
    public:
        DSU(int n){
            for(int i=0; i<n; i++){
                parent.push_back(i);
                rank.push_back(0);
            }
        }

        vector<int> getParent(){
            return parent;
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
    bool equationsPossible(vector<string>& equations) {
        DSU dsu = DSU(26);

        for(string &eq: equations){
            char x = eq[0];
            char y = eq[3];
            string op = eq.substr(1, 2);
            if(op == "=="){
                dsu.unionByRank(x-'a', y-'a');
            }
        }

        for(string &eq: equations){
            char x = eq[0];
            char y = eq[3];
            string op = eq.substr(1, 2);
            if(op == "!="){
                int parX = dsu.findParent(x-'a');
                int parY = dsu.findParent(y-'a');
                if(parX == parY){
                    return false;
                }
            }
        }
        return true;
    }
};
// PROBLEM:- https://leetcode.com/problems/satisfiability-of-equality-equations/description/
