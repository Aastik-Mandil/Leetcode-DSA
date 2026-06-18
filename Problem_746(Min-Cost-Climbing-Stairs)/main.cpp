class Solution {
    int stepR(vector<int> &cost, int idx){
        if(idx==(cost.size()+1)){
            return 0;
        }
        if(idx == 0){
            return min(
                stepR(cost, idx+1),
                stepR(cost, idx+2)
            );
        }
        if(idx+2 > (cost.size()+1)){
            return cost[idx-1] + stepR(cost, idx+1);
        }
        return cost[idx-1] + min(
            stepR(cost, idx+1),
            stepR(cost, idx+2)
        );
    }
    int stepM(vector<int> &cost, int idx, vector<int> &dp){
        if(idx==(cost.size()+1)){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        if(idx == 0){
            return dp[idx] = min(
                stepM(cost, idx+1, dp),
                stepM(cost, idx+2, dp)
            );
        }
        if(idx+2 > (cost.size()+1)){
            return dp[idx] = cost[idx-1] + stepM(cost, idx+1, dp);
        }
        return dp[idx] = cost[idx-1] + min(
            stepM(cost, idx+1, dp),
            stepM(cost, idx+2, dp)
        );
    }
    int stepT(vector<int> &cost){
        vector<int> dp(cost.size()+2, INT_MAX);
        dp[cost.size()+1] = 0;
        for(int idx=cost.size();idx>=0;idx--){
            if(idx == 0){
                dp[idx] = min(
                    dp[idx+1],
                    dp[idx+2]
                );
            }
            else if(idx+2 > (cost.size()+1)){
                dp[idx] = cost[idx-1] + dp[idx+1];
            }
            else{
                dp[idx] = cost[idx-1] + min(
                    dp[idx+1],
                    dp[idx+2]
                );
            }
        }
        return dp[0];
    }
    int stepO(vector<int> &cost){
        vector<int> dp(3, -1);
        dp[2] = 0;
        for(int idx=cost.size();idx>=0;idx--){
            if(idx+1 == (cost.size()+1)){
                dp[1] = cost[idx-1] + dp[2];
            }
            else if(idx == 0){
                dp[0] = min(
                    dp[1],
                    dp[2]
                );
            }
            else{
                dp[0] = cost[idx-1] + min(
                    dp[1],
                    dp[2]
                );
            }
            if(dp[0] != -1){
                dp[2] = dp[1];
                dp[1] = dp[0];
            }
        }
        return dp[0];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // return stepR(cost, 0);

        // vector<int> dp(cost.size()+1, -1);
        // return stepM(cost, 0, dp);

        // return stepT(cost);

        return stepO(cost);
    }
};
// PROBLEM:- https://leetcode.com/problems/min-cost-climbing-stairs/description/
