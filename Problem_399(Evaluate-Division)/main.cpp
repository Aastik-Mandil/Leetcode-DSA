class Solution {
    double BFS(unordered_map<string, vector<pair<string, double>>> &mp, string src, string dest){
        unordered_map<string, bool> visited;
        priority_queue<pair<double, string>, vector<pair<double, string>>, greater<pair<double, string>>> pq; // {wt, node}
        pq.push({1.00000, src});
        visited[src] = true;
        while(pq.size()>0){
            double wt = pq.top().first;
            string node = pq.top().second;
            pq.pop();
            if(dest == node){
                return wt;
            }
            for(pair<string, double> &p: mp[node]){
                string nbr = p.first;
                double cost = p.second;
                if(visited[nbr]){
                    continue;
                }
                pq.push({wt*cost, nbr});
                visited[nbr] = true;
            }
        }
        return -1.00000;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> mp;
        for(int i=0;i<equations.size();i++){
            string u = equations[i][0];
            string v = equations[i][1];
            double w = values[i];
            mp[u].push_back({v, w});
            mp[v].push_back({u, 1/w});
        }

        vector<double> ans;
        for(vector<string> &query: queries){
            string u = query[0];
            string v = query[1];
            if(mp.find(u) == mp.end() || mp.find(v) == mp.end()){
                ans.push_back(-1.00000);
            }
            else if(u == v){
                ans.push_back(1.00000);
            }
            else{
                double val = BFS(mp, u, v);
                ans.push_back(val);
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/evaluate-division/description/
