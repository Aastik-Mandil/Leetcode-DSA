class Solution {
public:
    int lisR(vector<int> &nums,int idx,int lastIdx){
        if(idx==0){
            return 0;
        }
        if(lastIdx == nums.size()+1 || nums[lastIdx-1]>nums[idx-1]){
            return max(
                lisR(nums,idx-1,lastIdx),
                1 + lisR(nums,idx-1,idx)
            );
        }
        return lisR(nums,idx-1,lastIdx);
    }
    int lisM(vector<int> &nums,int idx,int lastIdx,vector<vector<int>> &dp){
        if(idx==0 || lastIdx==0){
            return 0;
        }
        if(dp[idx][lastIdx] != -1){
            return dp[idx][lastIdx];
        }
        if(lastIdx == nums.size()+1 || nums[lastIdx-1]>nums[idx-1]){
            return dp[idx][lastIdx] = max(
                lisM(nums,idx-1,lastIdx,dp),
                1 + lisM(nums,idx-1,idx,dp)
            );
        }
        return dp[idx][lastIdx] = lisM(nums,idx-1,lastIdx,dp);
    }
    int lisT(vector<int> &nums){
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+2, -1));
        for(int lastIdx=0;lastIdx<(nums.size()+2);lastIdx++){
            dp[0][lastIdx]=0;
        }
        for(int idx=0;idx<=nums.size();idx++){
            dp[idx][0]=0;
        }
        for(int idx=1;idx<=nums.size();idx++){
            for(int lastIdx=1;lastIdx<=(nums.size()+1);lastIdx++){
                if(lastIdx == nums.size()+1 || nums[lastIdx-1] > nums[idx-1]){
                    dp[idx][lastIdx] = max(dp[idx-1][lastIdx], 1+dp[idx-1][idx]);
                }
                else{
                    dp[idx][lastIdx] = dp[idx-1][lastIdx];
                }
            }
        }
        return dp[nums.size()][nums.size()+1];
    }
    int lisO(vector<int> &nums){
        vector<int> dp(nums.size()+2, -1), curr(nums.size()+2, -1);
        for(int lastIdx=0;lastIdx<(nums.size()+2);lastIdx++){
            dp[lastIdx]=0;
        }
        for(int idx=1;idx<=nums.size();idx++){
            curr[0]=0;
            for(int lastIdx=1;lastIdx<=(nums.size()+1);lastIdx++){
                if(lastIdx == nums.size()+1 || nums[lastIdx-1] > nums[idx-1]){
                    curr[lastIdx] = max(dp[lastIdx], 1+dp[idx]);
                }
                else{
                    curr[lastIdx] = dp[lastIdx];
                }
            }
            dp=curr;
        }
        return dp[nums.size()+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        // return lisR(nums,nums.size(),nums.size()+1);

        // vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+2, -1));
        // return lisM(nums,nums.size(),nums.size()+1,dp);

        // return lisT(nums);

        return lisO(nums);
    }
};
// PROBLEM:- https://leetcode.com/problems/longest-increasing-subsequence/description/
