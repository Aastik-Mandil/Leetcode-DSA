class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        int maxi = nums[n-1];
        for(int i=n-2; i>=0; i--){
            if(maxi > nums[i]){
                ans = max(ans, maxi - nums[i]);
            }
            else{
                maxi = nums[i];
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/maximum-difference-between-increasing-elements/description/
