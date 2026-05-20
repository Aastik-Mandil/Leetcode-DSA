class Solution {
    int solveR(vector<int> &prices, int idx, int cnt, int buy){
        if(cnt == 0){
            return 0;
        }
        if(idx == 0){
            if(buy == 0){
                return 0;
            }
            return INT_MIN;
        }
        if(buy == 1){
            return max(
                solveR(prices, idx-1, cnt-1, 1^buy) - prices[idx-1],
                solveR(prices, idx-1, cnt, buy)
            );
        }
        return max(
            solveR(prices, idx-1, cnt, 1^buy) + prices[idx-1],
            solveR(prices, idx-1, cnt, buy)
        );
    }
    int solveM(vector<int> &prices, int idx, int cnt, int buy, vector<vector<vector<int>>> &dp){
        if(cnt == 0){
            return dp[idx][cnt][buy] = 0;
        }
        if(idx == 0){
            if(buy == 0){
                return dp[idx][cnt][buy] = 0;
            }
            return dp[idx][cnt][buy] = INT_MIN;
        }
        if(dp[idx][cnt][buy] != -1){
            return dp[idx][cnt][buy];
        }
        if(buy == 1){
            return dp[idx][cnt][buy] = max(
                solveM(prices, idx-1, cnt-1, 1^buy, dp) - prices[idx-1],
                solveM(prices, idx-1, cnt, buy, dp)
            );
        }
        return dp[idx][cnt][buy] = max(
            solveM(prices, idx-1, cnt, 1^buy, dp) + prices[idx-1],
            solveM(prices, idx-1, cnt, buy, dp)
        );
    }
    int solveT(vector<int> &prices, int k){
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(k+1, vector<int>(2, INT_MIN)));
        for(int idx=0; idx<=prices.size(); idx++){
            dp[idx][0][0] = 0;
        }
        for(int cnt = 1; cnt<=k; cnt++){
            dp[0][cnt][0] = 0;
        }
        for(int idx=1; idx<=prices.size(); idx++){
            for(int cnt = 1; cnt<=k; cnt++){
                for(int buy = 1; buy>=0; buy--){
                    if(buy == 1){
                        dp[idx][cnt][buy] = max(
                            dp[idx-1][cnt-1][1^buy] - prices[idx-1],
                            dp[idx-1][cnt][buy]
                        );
                    }
                    else{
                        dp[idx][cnt][buy] = max(
                            dp[idx-1][cnt][1^buy] + prices[idx-1],
                            dp[idx-1][cnt][buy]
                        );
                    }
                }
            }
        }
        return dp[prices.size()][k][0];
    }
    int solveO(vector<int> &prices, int k){
        vector<vector<int>> dp(k+1, vector<int>(2, INT_MIN)), curr(k+1, vector<int>(2, INT_MIN));
        dp[0][0] = curr[0][0] = 0;
        for(int cnt = 1; cnt<=k; cnt++){
            dp[cnt][0] = 0;
        }
        for(int idx=1; idx<=prices.size(); idx++){
            for(int cnt = 1; cnt<=k; cnt++){
                for(int buy = 1; buy>=0; buy--){
                    if(buy == 1){
                        curr[cnt][buy] = max(
                            dp[cnt-1][1^buy] - prices[idx-1],
                            dp[cnt][buy]
                        );
                    }
                    else{
                        curr[cnt][buy] = max(
                            dp[cnt][1^buy] + prices[idx-1],
                            dp[cnt][buy]
                        );
                    }
                }
            }
            dp = curr;
        }
        return dp[k][0];
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        // return solveR(prices, prices.size(), k, 0);

        // vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(k+1, vector<int>(2, -1)));
        // return solveM(prices, prices.size(), k, 0, dp);

        // return solveT(prices, k);

        return solveO(prices, k);
    }
};
// PROBLEM:- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description
