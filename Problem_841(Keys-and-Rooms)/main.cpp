class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(0);
        visited[0] = true;
        while(q.size()>0){
            int node = q.front();
            q.pop();
            for(int &nbr: rooms[node]){
                if(visited[nbr]){
                    continue;
                }
                q.push(nbr);
                visited[nbr] = true;
            }
        }

        for(int i=0; i<n; i++){
            if(visited[i] == false){
                return false;
            }
        }
        return true;
    }
};
// PROBLEM:- https://leetcode.com/problems/keys-and-rooms/description
