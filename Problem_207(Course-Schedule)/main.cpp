// Solution 1
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n,vector<int>());
        vector<int> indegree(n,0);
        for(vector<int> q: prerequisites){
            indegree[q[1]]++;
            adj[q[0]].push_back(q[1]);
        }

        int count=0;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(q.size()>0){
            int node=q.front();
            count++;
            q.pop();
            for(int nbr: adj[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }

        return count==n;
    }
};

// Solution 2
class Solution {
    bool DFS(vector<vector<int>> &adj, int node, vector<bool> &visited,  vector<bool> &pathVisited){
        if(pathVisited[node]){
            return false;
        }
        if(visited[node]){
            return true;
        }
        visited[node] = true;
        pathVisited[node] = true;
        for(int &nbr: adj[node]){
            bool res = DFS(adj, nbr, visited, pathVisited);
            if(!res){
                return false;
            }
        }
        pathVisited[node] = false;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        for(vector<int> &prerequisit: prerequisites){
            int u = prerequisit[0];
            int v = prerequisit[1];
            adj[u].push_back(v);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> pathVisited(numCourses, false);
        for(int i=0;i<numCourses;i++){
            if(visited[i]){
                continue;
            }
            bool res = DFS(adj, i, visited, pathVisited);
            if(!res){
                return false;
            }
        }
        return true;
    }
};
// PROBLEM:- https://leetcode.com/problems/course-schedule/
