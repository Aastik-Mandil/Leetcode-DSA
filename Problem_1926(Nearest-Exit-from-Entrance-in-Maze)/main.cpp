class Solution {
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool canMove(vector<vector<char>>& grid, int n, int m, int r, int c){
        return r>=0 && r<n && c>=0 && c<m && grid[r][c] == '.';
    }
public:
    int nearestExit(vector<vector<char>>& grid, vector<int>& entrance) {
        queue<vector<int>> q;
        int n = grid.size(), m = grid[0].size();
        q.push({0, entrance[0], entrance[1]});
        grid[entrance[0]][entrance[1]] = '+';

        int ans = INT_MAX;
        while(q.size() > 0){
            int val = q.front()[0];
            int i = q.front()[1];
            int j = q.front()[2];
            q.pop();
            for(vector<int> &dir: dirs){
                int newI = i+dir[0];
                int newJ = j+dir[1];
                if(canMove(grid, n, m, newI, newJ)){
                    if(newI == 0 || newI == n-1 || newJ == 0 || newJ == m-1){
                        ans = min(ans, val+1);
                    }
                    grid[newI][newJ] = '+';
                    q.push({val+1, newI, newJ});
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description
