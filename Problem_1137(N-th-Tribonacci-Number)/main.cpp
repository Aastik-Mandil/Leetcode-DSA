class Solution {
    int solveR(int n){
        if(n == 0){
            return 0;
        }
        if(n == 1 || n == 2){
            return 1;
        }
        return solveR(n-1) + solveR(n-2) + solveR(n-3);
    }
    int solveM(int n, vector<int> &dp){
        if(n == 0){
            return dp[n] = 0;
        }
        if(n == 1 || n == 2){
            return dp[n] = 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        return dp[n] = solveM(n-1, dp) + solveM(n-2, dp) + solveM(n-3, dp);
    }
    int solveT(int n){
        if(n == 0){
            return 0;
        }
        if(n == 1 || n == 2){
            return 1;
        }
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = dp[2] = 1;
        for(int i=3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
    }
    int solveO(int n){
        if(n == 0){
            return 0;
        }
        if(n == 1 || n == 2){
            return 1;
        }
        int a = 0, b = 1, c = 1;
        for(int i=3; i<=n; i++){
            int d = c + b + a;
            a = b;
            b = c; 
            c = d;
        }
        return c;
    }
public:
    int tribonacci(int n) {
        // return solveR(n);

        // vector<int> dp(n+1, -1);
        // return solveM(n, dp);

        // return solveT(n);

        return solveO(n);
    }
};
// PROBLEM:- https://leetcode.com/problems/n-th-tribonacci-number/description
