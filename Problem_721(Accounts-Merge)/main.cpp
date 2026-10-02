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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        unordered_map<string, int> mp;
        DSU dsu = DSU(n);
        
        for(int i=0; i<n; i++){
            string name = accounts[i][0];
            for(int j=1; j<accounts[i].size(); j++){
                string email = accounts[i][j];
                if(mp[email] > 0){
                    dsu.unionByRank(mp[email]-1, i);
                }
                else{
                    mp[email] = i+1;
                }
            }
        }

        vector<vector<string>> temp(n);
        for(auto &itr: mp){
            string mail = itr.first;
            int p = dsu.findParent(itr.second-1);
            temp[p].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
            if(temp[i].size() == 0){
                continue;
            }
            sort(temp[i].begin(), temp[i].end());
            temp[i].insert(temp[i].begin(), accounts[i][0]);
            ans.push_back(temp[i]);
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/accounts-merge/description/
