class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0;
        int ans=0;
        while(r<nums.size()>0){
            if(k==0 && nums[r]==0){
                ans=max(ans,r-l);
                while(l<=r && k==0){
                    if(nums[l]==0){
                        k++;
                    }
                    l++;
                }
            }
            if(nums[r]==0){
                k--;
            }
            r++;
        }
        return max(ans,r-l);
    }
};
// PROBLEM:- https://leetcode.com/problems/max-consecutive-ones-iii/
