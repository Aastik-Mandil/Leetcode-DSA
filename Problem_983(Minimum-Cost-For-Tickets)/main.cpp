class Solution {
    int solveR(vector<int>& days, vector<int>& costs, int idx, int currDate){
        if(idx == days.size()){
            return 0;
        }
        if(days[idx] < currDate){
            return solveR(days, costs, idx+1, currDate);
        }
        return min(
            costs[0] + solveR(days, costs, idx+1, min(366, days[idx]+1)), // 1-day pass
            min(
                costs[1] + solveR(days, costs, idx+1, min(366, days[idx]+7)), // 7-day pass
                costs[2] + solveR(days, costs, idx+1, min(366, days[idx]+30)) // 30-day pass
            )
        );
    }
    int solveM(vector<int>& days, vector<int>& costs, int idx, int currDate, vector<vector<int>> &dp){
        if(idx == days.size()){
            return 0;
        }
        if(dp[idx][currDate] != -1){
            return dp[idx][currDate];
        }
        if(days[idx] < currDate){
            return dp[idx][currDate] = solveM(days, costs, idx+1, currDate, dp);
        }
        return dp[idx][currDate] = min(
            costs[0] + solveM(days, costs, idx+1, min(366, days[idx]+1), dp), // 1-day pass
            min(
                costs[1] + solveM(days, costs, idx+1, min(366, days[idx]+7), dp), // 7-day pass
                costs[2] + solveM(days, costs, idx+1, min(366, days[idx]+30), dp) // 30-day pass
            )
        );
    }
    int solveT(vector<int>& days, vector<int>& costs){
        vector<vector<int>> dp(days.size()+1, vector<int>(367, 0));
        for(int idx=days.size()-1; idx>=0; idx--){
            for(int currDate=1; currDate<=366; currDate++){
                if(days[idx] < currDate){
                    dp[idx][currDate] = dp[idx+1][currDate];
                }
                else{
                    dp[idx][currDate] = min(
                        costs[0] + dp[idx+1][min(366, days[idx]+1)], // 1-day pass
                        min(
                            costs[1] + dp[idx+1][min(366, days[idx]+7)], // 7-day pass
                            costs[2] + dp[idx+1][min(366, days[idx]+30)] // 30-day pass
                        )
                    );
                }
            }
        }
        return dp[0][1];
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // return solveR(days, costs, 0, 1);

        // vector<vector<int>> dp(days.size()+1, vector<int>(367, -1));
        // return solveM(days, costs, 0, 1, dp);

        return solveT(days, costs);
    }
};
// PROBLEM:- https://leetcode.com/problems/minimum-cost-for-tickets/description/
