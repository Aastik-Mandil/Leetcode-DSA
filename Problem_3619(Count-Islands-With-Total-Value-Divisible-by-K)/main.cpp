class Solution {vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    bool canMove(vector<vector<int>> &grid, int n, int m, int x, int y){
        return x>=0 && y>=0 && x<n && y<m && grid[x][y] != 0;
    }
    long long getCount(vector<vector<int>> &grid, int n, int m, int x, int y){
        long long total = grid[x][y];
        grid[x][y] = 0;
        for(vector<int> &dir: dirs){
            int newX = x + dir[0];
            int newY = y + dir[1];
            if(canMove(grid, n, m, newX, newY)){
                total += getCount(grid, n, m, newX, newY);
            }
        }
        return total;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0){
                    continue;
                }
                long long val = getCount(grid, n, m, i, j);
                if(val%k == 0){
                    ans++;
                }
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/description/
