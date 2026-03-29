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
// PROBLEM:- https://leetcode.com/problems/course-schedule/
