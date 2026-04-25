class Solution {
    int lcsR(vector<int> &nums, int idx, int last){
        if(idx == 0){
            return 0;
        }
        if(last == nums.size()){
            return max(
                1+lcsR(nums, idx-1, idx-1),
                lcsR(nums, idx-1, last)
            );
        }
        if(nums[idx-1]+1 == nums[last]){
            return 1+lcsR(nums, idx-1, idx-1);
        }
        return lcsR(nums, idx-1, last);
    }
    int lcsM(vector<int> &nums, int idx, int last, vector<vector<int>> &dp){
        if(idx == 0){
            return 0;
        }
        if(dp[idx][last] != -1){
            return dp[idx][last];
        }
        if(last == nums.size()){
            return dp[idx][last] = max(
                1+lcsM(nums, idx-1, idx-1, dp),
                lcsM(nums, idx-1, last, dp)
            );
        }
        if(nums[idx-1]+1 == nums[last]){
            return dp[idx][last] = 1+lcsM(nums, idx-1, idx-1, dp);
        }
        return dp[idx][last] = lcsM(nums, idx-1, last, dp);
    }
    int lcsT(vector<int> &nums){
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, -1));
        for(int last=0;last<=nums.size();last++){
            dp[0][last] = 0;
        }
        for(int idx=1;idx<=nums.size();idx++){
            for(int last=0;last<=nums.size();last++){
                if(last == nums.size()){
                    dp[idx][last] = max(
                        1+dp[idx-1][idx-1],
                        dp[idx-1][last]
                    );
                }
                else if(nums[idx-1]+1 == nums[last]){
                    dp[idx][last] = 1+dp[idx-1][idx-1];
                }
                else{
                    dp[idx][last] = dp[idx-1][last];
                }
            }
        }
        return dp[nums.size()][nums.size()];
    }
    int lcsO(vector<int> &nums){
        vector<int> dp(nums.size()+1, 0), curr(nums.size()+1, 0);
        for(int idx=1;idx<=nums.size();idx++){
            for(int last=0;last<=nums.size();last++){
                if(last == nums.size()){
                    curr[last] = max(
                        1+dp[idx-1],
                        dp[last]
                    );
                }
                else if(nums[idx-1]+1 == nums[last]){
                    curr[last] = 1+dp[idx-1];
                }
                else{
                    curr[last] = dp[last];
                }
            }
            dp = curr;
        }
        return dp[nums.size()];
    }
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        // return lcsR(nums, nums.size(), nums.size());

        // vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, -1));
        // return lcsM(nums, nums.size(), nums.size(), dp);

        // return lcsT(nums);

        // return lcsO(nums);

        unordered_map<int, int> mp;
        int maxi = 0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = 1+mp[nums[i]-1];
            maxi = max(maxi, mp[nums[i]]);
        }
        return maxi;
    }
};
// PROBLEM:- https://leetcode.com/problems/longest-consecutive-sequence/description/
