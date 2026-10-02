class Solution {
    long long solveR(vector<int> &coins, int idx, int amount){
        if(amount == 0){
            return 0;
        }
        if(idx == 0){
            return INT_MAX;
        }
        long long notTaken = solveR(coins, idx-1, amount);
        long long taken = INT_MAX;
        if(coins[idx-1] <= amount){
            taken =  1 + solveR(coins, idx, amount-coins[idx-1]);
        }
        return min(notTaken, taken);
    }
    long long solveM(vector<int> &coins, int idx, int amount, vector<vector<int>> &dp){
        if(amount == 0){
            return 0;
        }
        if(idx == 0){
            return INT_MAX;
        }
        if(dp[idx][amount] != -1){
            return dp[idx][amount];
        }
        long long notTaken = solveM(coins, idx-1, amount, dp);
        long long taken = INT_MAX;
        if(coins[idx-1] <= amount){
            taken =  1 + solveM(coins, idx, amount-coins[idx-1], dp);
        }
        return dp[idx][amount] = min(notTaken, taken);
    }
    long long solveT(vector<int> &coins, int total){
        vector<vector<long long>> dp(coins.size()+1, vector<long long>(total+1, INT_MAX));
        for(int idx=0;idx<=coins.size();idx++){
            dp[idx][0] = 0;
        }
        for(int idx=1;idx<=coins.size();idx++){
            for(int amount=1;amount<=total;amount++){
                long long notTaken = dp[idx-1][amount];
                long long taken = INT_MAX;
                if(coins[idx-1] <= amount){
                    taken =  1 + dp[idx][amount-coins[idx-1]];
                }
                dp[idx][amount] = min(notTaken, taken);
            }
        }
        return dp[coins.size()][total];
    }
    long long solveO(vector<int> &coins, int total){
        vector<long long> dp(total+1, INT_MAX), curr(total+1, INT_MAX);
        dp[0] = curr[0] = 0;
        for(int idx=1;idx<=coins.size();idx++){
            for(int amount=1;amount<=total;amount++){
                long long notTaken = dp[amount];
                long long taken = INT_MAX;
                if(coins[idx-1] <= amount){
                    taken =  1 + curr[amount-coins[idx-1]];
                }
                curr[amount] = min(notTaken, taken);
            }
            dp = curr;
        }
        return dp[total];
    }
public:
    long long coinChange(vector<int>& coins, int amount) {
        // long long val = solveR(coins, coins.size(), amount);

        // vector<vector<long long>> dp(coins.size()+1, vector<long long>(amount+1, -1));
        // long long val = solveM(coins, coins.size(), amount, dp);

        // long long val = solveT(coins, amount);

        long long val = solveO(coins, amount);

        return val >= INT_MAX ? -1 : val;
    }
};
// PROBLEM:- https://leetcode.com/problems/coin-change/description/
