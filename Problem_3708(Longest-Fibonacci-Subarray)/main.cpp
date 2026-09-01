class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        if(nums.size() == 1){
            return 1;
        }

        int ans = 2;
        int l = 0, r = 0;
        while(r < nums.size()){
            while(r-l+1 > 2 && nums[r-1]+nums[r-2] != nums[r]){
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/longest-fibonacci-subarray/description/
