class Solution {
    int solveR(vector<int> &costs, int idx, int coins){
        if(coins == 0 || idx == 0){
            return 0;
        }
        if(costs[idx-1] > coins){
            return solveR(costs, idx-1, coins);
        }
        return max(
            1 + solveR(costs, idx-1, coins-costs[idx-1]),
            solveR(costs, idx-1, coins)
        );
    }
    int solveM(vector<int> &costs, int idx, int coins, vector<vector<int>> &dp){
        if(coins == 0 || idx == 0){
            return dp[idx][coins] = 0;
        }
        if(dp[idx][coins] != -1){
            return dp[idx][coins];
        }
        if(costs[idx-1] > coins){
            return dp[idx][coins] = solveM(costs, idx-1, coins, dp);
        }
        return dp[idx][coins] = max(
            1 + solveM(costs, idx-1, coins-costs[idx-1], dp),
            solveM(costs, idx-1, coins, dp)
        );
    }
    int solveT(vector<int> &costs, int coins){
        int n = costs.size();
        vector<vector<int>> dp(n+1, vector<int>(coins+1, 0));
        for(int idx=1; idx<=n; idx++){
            for(int coin=1; coin<=coins; coin++){
                if(costs[idx-1] > coin){
                    dp[idx][coin] = dp[idx-1][coin];
                }
                else{
                    dp[idx][coin] = max(
                        1 + dp[idx-1][coin-costs[idx-1]],
                        dp[idx-1][coin]
                    );
                }
            }
        }
        return dp[n][coins];
    }
    int solveO(vector<int> &costs, int coins){
        int n = costs.size();
        vector<int> dp(coins+1, 0), curr(coins+1, 0);
        for(int idx=1; idx<=n; idx++){
            for(int coin=1; coin<=coins; coin++){
                if(costs[idx-1] > coin){
                    curr[coin] = dp[coin];
                }
                else{
                    curr[coin] = max(
                        1 + dp[coin-costs[idx-1]],
                        dp[coin]
                    );
                }
            }
            dp = curr;
        }
        return dp[coins];
    }
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();

        // return solveR(costs, n, coins);

        // vector<vector<int>> dp(n+1, vector<int>(coins+1, -1));
        // return solveM(costs, n, coins, dp);

        // return solveT(costs, coins);

        // return solveO(costs, coins);

        sort(costs.begin(), costs.end());
        int count = 0;
        for(int i=0; i<n && coins>=costs[i]; i++){
            count++;
            coins -= costs[i];
        }
        return count;
    }
};
// PROBLEM:- https://leetcode.com/problems/maximum-ice-cream-bars/description/
