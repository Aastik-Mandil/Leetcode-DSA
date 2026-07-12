class Solution {
    int solveR(vector<int> &nums, int idx, int st){
        if(idx <= st){
            return 0;
        }
        int taken = nums[idx-1];
        if(idx-2 >= st){
            taken += solveR(nums, idx-2, st);
        }
        int notTaken = solveR(nums, idx-1, st);
        return max(taken, notTaken);
    }
    int solveM(vector<int> &nums, vector<vector<int>> &dp, int idx, int st){
        if(idx <= st){
            return dp[idx][st] = 0;
        }
        if(dp[idx][st] != -1){
            return dp[idx][st];
        }
        int taken = nums[idx-1];
        if(idx-2 >= st){
            taken += solveM(nums, dp, idx-2, st);
        }
        int notTaken = solveM(nums, dp, idx-1, st);
        return dp[idx][st] = max(taken, notTaken);
    }
    int solveT(vector<int> &nums){
        vector<vector<int>> dp(nums.size()+1, vector<int>(2, -1));
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[1][1] = 0;
        // st = 1;
        for(int idx=2; idx<=nums.size(); idx++){
            int taken = nums[idx-1];
            if(idx-2 >= 1){
                taken += dp[idx-2][1];
            }
            int notTaken = dp[idx-1][1];
            dp[idx][1] = max(taken, notTaken);
        }
        // st = 0;
        for(int idx=1; idx<=(nums.size()-1); idx++){
            int taken = nums[idx-1];
            if(idx-2 >= 0){
                taken += dp[idx-2][0];
            }
            int notTaken = dp[idx-1][0];
            dp[idx][0] = max(taken, notTaken);
        }
        return max(dp[nums.size()][1], dp[nums.size()-1][0]);
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }

        // return max(
        //     solveR(nums, nums.size(), 1),
        //     solveR(nums, nums.size()-1, 0)
        // );

        // vector<vector<int>> dp(nums.size()+1, vector<int>(2, -1));
        // return max(
        //     solveM(nums, dp, nums.size(), 1),
        //     solveM(nums, dp, nums.size()-1, 0)
        // );

        return solveT(nums);
    }
};
// PROBLEM:- https://leetcode.com/problems/house-robber-ii/description/
