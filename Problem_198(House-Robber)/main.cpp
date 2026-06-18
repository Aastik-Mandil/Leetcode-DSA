class Solution {
    int solveR(vector<int> &nums, int idx){
        if(idx == 0){
            return 0;
        }
        if(idx == 1){
            return nums[idx-1];
        }
        return max(
            nums[idx-1] + solveR(nums, idx-2),
            solveR(nums, idx-1)
        );
    }
    int solveM(vector<int> &nums, int idx, vector<int> &dp){
        if(idx == 0){
            return 0;
        }
        if(idx == 1){
            return dp[idx] = nums[idx-1];
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        return dp[idx] = max(
            nums[idx-1] + solveM(nums, idx-2, dp),
            solveM(nums, idx-1, dp)
        );
    }
    int solveT(vector<int> &nums){
        vector<int> dp(nums.size()+1, -1);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int idx=2; idx<=nums.size(); idx++){
            dp[idx] = max(
                nums[idx-1] + dp[idx-2],
                dp[idx-1]
            );
        }
        return dp[nums.size()];
    }
public:
    int rob(vector<int>& nums) {
        // return solveR(nums, nums.size());

        // vector<int> dp(nums.size()+1, -1);
        // return solveM(nums, nums.size(), dp);

        return solveT(nums);
    }
};
// PROBLEM:- https://leetcode.com/problems/house-robber/description
