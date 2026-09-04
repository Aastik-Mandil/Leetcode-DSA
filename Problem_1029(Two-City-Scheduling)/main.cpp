class Solution {
    int solveR(vector<vector<int>> &costs, int idx, int cntA){
        if(idx == 0){
            return 0;
        }
        if(cntA == 0){
            return costs[idx-1][1] + solveR(costs, idx-1, cntA);
        }
        if(idx-cntA == 0){
            return costs[idx-1][0] + solveR(costs, idx-1, cntA-1);
        }
        return min(
            costs[idx-1][1] + solveR(costs, idx-1, cntA),
            costs[idx-1][0] + solveR(costs, idx-1, cntA-1)
        );
    }
    int solveM(vector<vector<int>> &costs, int idx, int cntA, vector<vector<int>> &dp){
        if(idx == 0){
            return 0;
        }
        if(dp[idx][cntA] != -1){
            return dp[idx][cntA];
        }
        if(cntA == 0){
            return dp[idx][cntA] = costs[idx-1][1] + solveM(costs, idx-1, cntA, dp);
        }
        if(idx-cntA == 0){
            return dp[idx][cntA] = costs[idx-1][0] + solveM(costs, idx-1, cntA-1, dp);
        }
        return dp[idx][cntA] = min(
            costs[idx-1][1] + solveM(costs, idx-1, cntA, dp),
            costs[idx-1][0] + solveM(costs, idx-1, cntA-1, dp)
        );
    }
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size(), m = costs.size()/2;

        // return solveR(costs, n, m);

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solveM(costs, n, m, dp);
    }
};
// PROBLEM:- https://leetcode.com/problems/two-city-scheduling/description/
