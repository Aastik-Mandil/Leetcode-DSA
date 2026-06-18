class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses, vector<int>());
        for(vector<int> &prerequisit: prerequisites){
            int u = prerequisit[0];
            int v = prerequisit[1];
            indegree[u]++;
            adj[v].push_back(u);
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(q.size()>0){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int &nbr: adj[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        if(ans.size() != numCourses){
            return {};
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/course-schedule-ii/description/
