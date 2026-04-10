class Solution {
public:
    bool jumpR(vector<int> &nums, int idx){
        if(idx==nums.size()-1){
            return true;
        }
        int end=nums[idx];
        if(end>(nums.size()-1)){
            end=nums.size()-1;
        }
        for(int i=1;i<=end;i++){
            if(jumpR(nums,idx+i)){
                return true;
            }
        }
        return false;
    }
    int jumpM(vector<int> &nums, int idx, vector<int> &dp){
        if(idx==nums.size()-1){
            return 1;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int end=nums[idx];
        if(end>(nums.size()-1)){
            end=nums.size()-1;
        }
        for(int i=1;i<=end;i++){
            if(jumpM(nums,idx+i,dp)){
                return dp[idx]=1;
            }
        }
        return dp[idx]=0;
    }
    int jumpT(vector<int> &nums){
        vector<int> dp(nums.size(), -1);
        dp[nums.size()-1]=1;
        for(int idx=nums.size()-2;idx>=0;idx--){
            int end=nums[idx];
            if(end>(nums.size()-1)){
                end=nums.size()-1;
            }
            for(int i=1;i<=end;i++){
                int ind=idx+i;
                if(ind>nums.size()-1){
                    ind=nums.size()-1;
                }
                if(dp[ind] == 1){
                    dp[idx] = 1;
                }
            }
        }
        return dp[0];
    }
    bool canJump(vector<int>& nums) {
        // return jumpR(nums,0);

        // vector<int> dp(nums.size(),-1);
        // return jumpM(nums,0,dp)==1;

        return jumpT(nums)==1;
    }
};
// PROBLEM:- https://leetcode.com/problems/jump-game/description/
