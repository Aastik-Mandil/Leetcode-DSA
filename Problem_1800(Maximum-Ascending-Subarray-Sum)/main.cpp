class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int total = nums[0], ans = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > nums[i-1]){
                total += nums[i];
            }
            else{
                ans = max(ans, total);
                total = nums[i];
            }
        }
        return max(ans, total);
    }
};
// PROBLEM:- https://leetcode.com/problems/maximum-ascending-subarray-sum/description/
