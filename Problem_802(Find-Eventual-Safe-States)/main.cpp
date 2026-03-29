class Solution {
public:
    void dfs(vector<vector<int>> &graph,int u,vector<bool> &visited,vector<bool> &pathVisited){
        int n=graph.size();
        visited[u]=true;
        pathVisited[u]=true;
        for(int i=0;i<graph[u].size();i++){
            int v=graph[u][i];
            if(!visited[v]){
                dfs(graph,v,visited,pathVisited);
            }
            if(pathVisited[v]){
                return;
            }
        }
        pathVisited[u]=false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> visited(n,false);
        vector<bool> pathVisited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]){
                continue;
            }
            dfs(graph,i,visited,pathVisited);
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!pathVisited[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/find-eventual-safe-states/
