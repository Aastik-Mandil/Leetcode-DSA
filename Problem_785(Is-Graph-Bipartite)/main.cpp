class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<int> q;
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
                q.push(i);
                while(q.size()>0){
                    int node=q.front();
                    q.pop();
                    for(auto nbr: graph[node]){
                        if(color[nbr]==-1){
                            color[nbr] = 1^color[node];
                            q.push(nbr);
                        }
                        else{
                            if(color[nbr] != 1^color[node]){
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
// PROBLEM:- https://leetcode.com/problems/is-graph-bipartite/description/
