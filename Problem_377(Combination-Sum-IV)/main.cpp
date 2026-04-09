class Solution {
    int solveR(vector<int> &nums, int idx, int target){
        if(target == 0){
            return 1;
        }
        if(idx == nums.size()){
            return 0;
        }
        int take = 0;
        if(target>=nums[idx]){
            take = solveR(nums, 0, target-nums[idx]);
        }
        int notTake = solveR(nums, idx+1, target);
        return take + notTake;
    }
    int solveM(vector<int> &nums, int idx, int target, vector<vector<int>> &dp){
        if(target == 0){
            return dp[idx][target] = 1;
        }
        if(idx == nums.size()){
            return dp[idx][target] = 0;
        }
        if(dp[idx][target] != -1){
            return dp[idx][target];
        }
        int take = 0;
        if(target>=nums[idx]){
            take = solveM(nums, 0, target-nums[idx], dp);
        }
        int notTake = solveM(nums, idx+1, target, dp);
        return dp[idx][target] = take + notTake;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        // return solveR(nums, 0, target);

        vector<vector<int>> dp(nums.size()+1, vector<int>(target+1,-1));
        return solveM(nums, 0, target, dp);
    }
};
// PROBLEM:- https://leetcode.com/problems/combination-sum-iv/description/
