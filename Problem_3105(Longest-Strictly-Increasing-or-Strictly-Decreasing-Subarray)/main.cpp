class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 0;
        // increasing
        int count = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > nums[i-1]){
                count++;
            }
            else{
                ans = max(ans, count);
                count = 1;
            }
        }
        ans = max(ans, count);

        // decreasing
        count = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] < nums[i-1]){
                count++;
            }
            else{
                ans = max(ans, count);
                count = 1;
            }
        }
        ans = max(ans, count);

        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/description/
