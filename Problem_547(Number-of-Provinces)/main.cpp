class Solution {
public:
    void bfs(vector<vector<int>> &isConnected,queue<int> &q,vector<bool> &visited){
        int n=isConnected.size();
        while(q.size()>0){
            int node = q.front();
            q.pop();
            for(int j=0;j<n;j++){
                if(visited[j] || isConnected[node][j]==0){
                    continue;
                }
                q.push(j);
                visited[j]=true;
            }
        }
    }
    int findByBFS(vector<vector<int>> &isConnected){
        int n=isConnected.size();
        queue<int> q;
        vector<bool> visited(n,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(visited[i]){
                continue;
            }
            ans++;
            q.push(i);
            visited[i]=true;
            bfs(isConnected,q,visited);
        }
        return ans;
    }

    void dfs(vector<vector<int>> &isConnected,vector<bool> &visited,int node){
        int n=isConnected.size();
        visited[node]=true;
        for(int j=0;j<n;j++){
            if(visited[j] || isConnected[node][j]==0){
                continue;
            }
            dfs(isConnected, visited, j);
        }
    }
    int findByDFS(vector<vector<int>> &isConnected){
        int n=isConnected.size();
        vector<bool> visited(n,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(visited[i]){
                continue;
            }
            ans++;
            dfs(isConnected,visited,i);
        }
        return ans;
    }

    int find(int u,vector<int> &parent){
        if(parent[u] == u){
            return u;
        }
        return parent[u] = find(parent[u], parent);
    }
    void unionByRank(int u,int v,vector<int> &parent,vector<int> &rank){
        int uParent = find(u, parent);
        int vParent = find(v, parent);
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
    int findByDSU(vector<vector<int>> &isConnected){
        int n = isConnected.size();
        vector<int> parent(n,-1);
        vector<int> rank(n,0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j] == 1){
                    unionByRank(i,j,parent,rank);
                }
            }
        }
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(find(i,parent));
        }
        return st.size();
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        // return findByBFS(isConnected);

        // return findByDFS(isConnected);

        return findByDSU(isConnected);
    }
};
// PROBLEM:- https://leetcode.com/problems/number-of-provinces/
