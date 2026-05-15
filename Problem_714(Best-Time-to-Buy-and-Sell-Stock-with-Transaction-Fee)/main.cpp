class Solution {
    int solveR(vector<int> &prices, int fee, int idx, int canBuy){
        if(idx == 0){
            if(canBuy){
                return INT_MIN;
            }
            return 0;
        }
        if(canBuy){
            return max(
                solveR(prices, fee, idx-1, canBuy),
                solveR(prices, fee, idx-1, 1^canBuy) - prices[idx-1] - fee
            );
        }
        return max(
            solveR(prices, fee, idx-1, canBuy),
            solveR(prices, fee, idx-1, 1^canBuy) + prices[idx-1]
        );
    }
    int solveM(vector<int> &prices, int fee, int idx, int canBuy, vector<vector<int>> &dp){
        if(idx == 0){
            if(canBuy){
                return INT_MIN;
            }
            return 0;
        }
        if(dp[idx][canBuy] != -1){
            return dp[idx][canBuy];
        }
        if(canBuy){
            return dp[idx][canBuy] = max(
                solveM(prices, fee, idx-1, canBuy, dp),
                solveM(prices, fee, idx-1, 1^canBuy, dp) - prices[idx-1] - fee
            );
        }
        return dp[idx][canBuy] = max(
            solveM(prices, fee, idx-1, canBuy, dp),
            solveM(prices, fee, idx-1, 1^canBuy, dp) + prices[idx-1]
        );
    }
    int solveT(vector<int> &prices, int fee){
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, INT_MIN));
        dp[0][0] = 0;
        for(int idx=1; idx<=prices.size(); idx++){
            for(int canBuy=1; canBuy>=0; canBuy--){
                if(canBuy){
                    dp[idx][canBuy] = max(dp[idx-1][canBuy], dp[idx-1][1^canBuy] - prices[idx-1] - fee);
                }
                else{
                    dp[idx][canBuy] = max(dp[idx-1][canBuy], dp[idx-1][1^canBuy] + prices[idx-1]);
                }
            }
        }
        return dp[prices.size()][0];
    }
    int solveO(vector<int> &prices, int fee){
        vector<int> dp(2, INT_MIN), curr(2, INT_MIN);
        dp[0] = curr[0] = 0;
        for(int idx=1; idx<=prices.size(); idx++){
            for(int canBuy=1; canBuy>=0; canBuy--){
                if(canBuy){
                    curr[canBuy] = max(dp[canBuy], dp[1^canBuy] - prices[idx-1] - fee);
                }
                else{
                    curr[canBuy] = max(dp[canBuy], dp[1^canBuy] + prices[idx-1]);
                }
            }
            dp = curr;
        }
        return dp[0];
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        // return solveR(prices, fee, prices.size(), 0);

        // vector<vector<int>> dp(prices.size()+1, vector<int>(2, -1));
        // return solveM(prices, fee, prices.size(), 0, dp);

        // return solveT(prices, fee);

        return solveO(prices, fee);
    }
};
// PROBLEM:- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description
