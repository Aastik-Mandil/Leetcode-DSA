long long mod = 2 * 1e9;

class Solution {
    int solveR(int m, int n, int r, int c){
        if(r == m || c == n){
            return 1;
        }
        return solveR(m, n, r+1, c) + solveR(m, n, r, c+1);
    }
    int solveM(int m, int n, int r, int c, vector<vector<int>> &dp){
        if(r == m || c == n){
            return dp[r][c] = 1;
        }
        if(dp[r][c] != -1){
            return dp[r][c];
        }
        return dp[r][c] = solveM(m, n, r+1, c, dp) + solveM(m, n, r, c+1, dp);
    }
    int solveT(int m, int n){
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        for(int r=0; r<=m; r++){
            dp[r][n] = 1;
        }
        for(int c=0; c<=n; c++){
            dp[m][c] = 1;
        }
        for(int r=m-1; r>=0; r--){
            for(int c=n-1; c>=0; c--){
                dp[r][c] = dp[r+1][c] + dp[r][c+1];
            }
        }
        return dp[0][0];
    }
    int solveO(int m, int n){
        vector<int> dp(n+1, 1), curr(n+1, -1);
        for(int r=m-1; r>=0; r--){
            curr[n] = 1;
            for(int c=n-1; c>=0; c--){
                curr[c] = dp[c] + curr[c+1];
            }
            dp = curr;
        }
        return dp[0];
    }
public:
    int uniquePaths(int m, int n) {
        // return solveR(m-1, n-1, 0, 0);

        // vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        // return solveM(m-1, n-1, 0, 0, dp);

        // return solveT(m-1, n-1);

        return solveO(m-1, n-1);
    }
};
// PROBLEM:- https://leetcode.com/problems/unique-paths/description
