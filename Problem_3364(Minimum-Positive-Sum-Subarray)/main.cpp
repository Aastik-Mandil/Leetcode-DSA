class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            int total = 0;
            for(int j=i; j<n && j<(i+r); j++){
                total += nums[j];
                if(j-i+1 >= l && j-i+1 <= r && total > 0){
                    mini = min(mini, total);
                }
            }
        }
        return mini == INT_MAX ? -1 : mini;
    }
};
// PROBLEM:- https://leetcode.com/problems/minimum-positive-sum-subarray/description/
