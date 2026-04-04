class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int total=0,i=0,j=0;
        while(j<nums.size()){
            total+=nums[j];
            while(i<=j && total>=target){
                ans=min(ans,j-i+1);
                total-=nums[i];
                i++;
            }
            j++;
        }
        return ans==INT_MAX ? 0 : ans;
    }
};
// Problem_209(Minimum-Size-Subarray-Sum)
// PROBLEM:- https://leetcode.com/problems/minimum-size-subarray-sum/
