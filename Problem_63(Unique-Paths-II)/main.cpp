long long mod = 2 * 1e9;

class Solution {
    long long pathR(vector<vector<int>> &grid, int n, int m, int r, int c){
        if(r == n && c == m){
            return 1;
        }
        if(grid[r][c] == 1){
            return 0;
        }
        if(r == n){
            return pathR(grid, n, m, r, c+1);
        }
        if(c == m){
            return pathR(grid, n, m, r+1, c);
        }
        return pathR(grid, n, m, r+1, c) + pathR(grid, n, m, r, c+1);
    }
    long long pathM(vector<vector<int>> &grid, int n, int m, int r, int c, vector<vector<long long>> &dp){
        if(r == n && c == m){
            return dp[r][c] = 1;
        }
        if(dp[r][c] != -1){
            return dp[r][c];
        }
        if(grid[r][c] == 1){
            return dp[r][c] = 0;
        }
        if(r == n){
            return dp[r][c] = pathM(grid, n, m, r, c+1, dp);
        }
        if(c == m){
            return dp[r][c] = pathM(grid, n, m, r+1, c, dp);
        }
        return dp[r][c] = pathM(grid, n, m, r+1, c, dp) + pathM(grid, n, m, r, c+1, dp);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[n-1][m-1] == 1 || grid[0][0] == 1){
            return 0;
        }

        // long long val = pathR(grid, n-1, m-1, 0, 0);

        vector<vector<long long>> dp(n, vector<long long>(m, -1));
        long long val = pathM(grid, n-1, m-1, 0, 0, dp);

        return val%mod;
    }
};
// PROBLEM:- https://leetcode.com/problems/unique-paths-ii/description
