class Solution {
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool canMove(vector<vector<int>>& grid, int n, int m, int r, int c){
        return r>=0 && r<n && c>=0 && c<m && grid[r][c] == 1;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size(), m = grid[0].size();
        int count1 = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    count1++;
                }
            }
        }

        int count = 0;
        int ans = 0;
        while(q.size() > 0){
            int size = q.size();
            ans++;
            while(size--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(vector<int> &dir: dirs){
                    int newI = i+dir[0];
                    int newJ = j+dir[1];
                    if(canMove(grid, n, m, newI, newJ)){
                        count++;
                        grid[newI][newJ] = 2;
                        q.push({newI, newJ});
                    }
                }
            }
        }

        if(count1 != count){
            return -1;
        }

        if(ans == 0){
            return 0;
        }
        return ans-1;
    }
};
// PROBLEM:- https://leetcode.com/problems/rotting-oranges/description
