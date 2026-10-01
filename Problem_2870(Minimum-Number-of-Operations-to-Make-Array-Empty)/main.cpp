class Solution {
    int getMinCountM(int n, vector<int> &dp){
        if(n == 0){
            return dp[n] = 0;
        }
        if(n == 1){
            return dp[n] = INT_MAX;
        }
        if(dp[n] != INT_MAX){
            return dp[n];
        }
        if(n == 2){
            return dp[n] = 1 + getMinCountM(n-2, dp);
        }
        return dp[n] = min(
            dp[n],
            1 + min(
                getMinCountM(n-2, dp),
                getMinCountM(n-3, dp)
            )
        );
    }
public:
    int minOperations(vector<int>& nums) {
        int maxi = 0;
        unordered_map<int, int> mp;
        for(int &num: nums){
            mp[num]++;
            maxi = max(maxi, mp[num]);
        }

        vector<int> dp(maxi+1, INT_MAX);
        for(int i=0; i<=maxi; i++){
            getMinCountM(i, dp);
        }

        long long ans = 0;
        for(auto itr=mp.begin(); itr!=mp.end(); itr++){
            ans += dp[itr->second];
            if(ans >= INT_MAX){
                return -1;
            }
        }
        return ans >= INT_MAX ? -1 : ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/
