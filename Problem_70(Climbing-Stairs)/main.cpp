class Solution {
    int solveR(int n){
        if(n<=1){
            return 1;
        }
        return solveR(n-1) + solveR(n-2);
    }
    int solveM(int n, vector<int> &dp){
        if(n<=1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        return dp[n] = solveM(n-1, dp) + solveM(n-2, dp);
    }
    int solveT(int n){
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;
        for(int idx=2;idx<=n;idx++){
            dp[idx] = dp[idx-1] + dp[idx-2];
        }
        return dp[n];
    }
    int solveO(int n){
        if(n <= 1){
            return 1;
        }
        int a = 1;
        int b = 1;
        for(int idx=2;idx<=n;idx++){
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
public:
    int climbStairs(int n) {
        // return solveR(n);

        // vector<int> dp(n+1, -1);
        // return solveM(n, dp);

        // return solveT(n);

        return solveO(n);
    }
};
// PROBLEM:- https://leetcode.com/problems/climbing-stairs/description
