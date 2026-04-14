class Solution {
    int sumR(vector<int> &nums, int idx, int taken){
        if(idx == 0){
            if(taken == 0){
                return INT_MIN;
            }
            return 0;
        }
        if(taken == 1){
            return max(0, nums[idx-1] + sumR(nums, idx-1, taken));
        }
        return max(
            sumR(nums, idx-1, taken),
            nums[idx-1] + sumR(nums, idx-1, 1^taken)
        );
    }
    int sumM(vector<int> &nums, int idx, int taken, vector<vector<int>> &dp){
        if(idx == 0){
            if(taken == 0){
                return INT_MIN;
            }
            return 0;
        }
        if(dp[idx][taken] != -1){
            return dp[idx][taken];
        }
        if(taken == 1){
            return dp[idx][taken] = max(0, nums[idx-1] + sumM(nums, idx-1, taken, dp));
        }
        return dp[idx][taken] = max(
            sumM(nums, idx-1, taken, dp),
            nums[idx-1] + sumM(nums, idx-1, 1^taken, dp)
        );
    }
    int sumT(vector<int> &nums){
        vector<vector<int>> dp(nums.size()+1, vector<int> (2, -1));
        dp[0][0] = INT_MIN;
        dp[0][1] = 0;
        for(int idx=1;idx<=nums.size();idx++){
            for(int taken=0;taken<2;taken++){
                if(taken == 1){
                    dp[idx][taken] = max(0, nums[idx-1] + dp[idx-1][taken]);
                }
                else{
                    dp[idx][taken] = max(
                        dp[idx-1][taken],
                        nums[idx-1] + dp[idx-1][1^taken]
                    );
                }
            }
        }
        return dp[nums.size()][0];
    }
    int sumO(vector<int> &nums){
        vector<int> dp(2, 0), curr(2,0);
        dp[0] = curr[0] = INT_MIN;
        for(int idx=1;idx<=nums.size();idx++){
            for(int taken=0;taken<2;taken++){
                if(taken == 1){
                    curr[taken] = max(0, nums[idx-1] + dp[taken]);
                }
                else{
                    curr[taken] = max(
                        dp[taken],
                        nums[idx-1] + dp[1^taken]
                    );
                }
            }
            dp = curr;
        }
        return dp[0];
    }
public:
    int maxSubArray(vector<int>& nums) {
        // return sumR(nums, nums.size(), 0);

        // vector<vector<int>> dp(nums.size()+1, vector<int> (2, -1));
        // return sumM(nums, nums.size(), 0, dp);

        // return sumT(nums);
        
        return sumO(nums);
    }
};
// PROBLEM:- https://leetcode.com/problems/maximum-subarray/description/
