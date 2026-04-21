class Solution {
    int solveR(vector<int> &nums, int idx, int take){
        if(idx == 0){
            if(take == 1){
                return 0;
            }
            return INT_MIN;
        }
        if(take == 1){
            return max(0, nums[idx-1] + solveR(nums, idx-1, take));
        }
        return max(
            solveR(nums, idx-1, take),
            nums[idx-1] + solveR(nums, idx-1, 1^take)
        );
    }
    int solveM(vector<int> &nums, int idx, int take, vector<vector<int>> &dp){
        if(idx == 0){
            if(take == 1){
                return 0;
            }
            return INT_MIN;
        }
        if(dp[idx][take] != -1){
            return dp[idx][take];
        }
        if(take == 1){
            return dp[idx][take] = max(0, nums[idx-1] + solveM(nums, idx-1, take, dp));
        }
        return dp[idx][take] = max(
            solveM(nums, idx-1, take, dp),
            nums[idx-1] + solveM(nums, idx-1, 1^take, dp)
        );
    }
    int solveT(vector<int> &nums){
        vector<vector<int>> dp(nums.size()+1, vector<int> (2, INT_MIN));
        dp[0][1] = 0;
        for(int idx=1; idx<=nums.size(); idx++){
            for(int take=1; take>=0; take--){
                if(take == 1){
                    dp[idx][take] = max(0, nums[idx-1]+dp[idx-1][take]);
                }
                else{
                    dp[idx][take] = max(dp[idx-1][take], nums[idx-1]+dp[idx-1][1^take]);
                }
            }
        }
        return dp[nums.size()][0];
    }
    int solveO(vector<int> &nums){
        vector<int> dp(2, INT_MIN), curr(2, INT_MIN);
        dp[1] = curr[0] = 0;
        for(int idx=1; idx<=nums.size(); idx++){
            for(int take=1; take>=0; take--){
                if(take == 1){
                    curr[take] = max(0, nums[idx-1]+dp[take]);
                }
                else{
                    curr[take] = max(dp[take], nums[idx-1]+dp[1^take]);
                }
            }
            dp = curr;
        }
        return dp[0];
    }
public:
    int maxSubArray(vector<int>& nums) {
        // return solveR(nums, nums.size(), 0);

        // vector<vector<int>> dp(nums.size()+1, vector<int> (2, -1));
        // return solveM(nums, nums.size(), 0, dp);

        // return solveT(nums);

        return solveO(nums);
    }
};
// PROBLEM:- https://leetcode.com/problems/maximum-subarray/description
