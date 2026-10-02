class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();
        for(int i=n-2; i>=0; i--){
            if(nums[i] >= nums[i+1]){
                return i+1;
            }
        }
        return 0;
    }
};
// PROBLEM:- https://leetcode.com/problems/minimum-prefix-removal-to-make-array-strictly-increasing/description/
