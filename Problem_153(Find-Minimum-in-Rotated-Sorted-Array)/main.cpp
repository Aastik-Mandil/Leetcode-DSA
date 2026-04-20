class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l<r){
            int mid = l+((r-l)/2);
            if(mid == l){
                // return min()
                break;
            }
            if(nums[l]>nums[mid] && nums[r]>nums[mid]){
                r = mid;
            }
            else if(nums[r]<nums[mid] && nums[l]<nums[mid]){
                l = mid+1;
            }
            else if(nums[l]<=nums[mid]){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        int val = INT_MAX;
        if(l>=0 && l<nums.size()){
            val = nums[l];
        }
        if(r>=0 && r<nums.size()){
            val = min(val, nums[r]);
        }
        return val;
    }
};
// PROBLEM:- https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description
