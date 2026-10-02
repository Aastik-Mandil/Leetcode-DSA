class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        if(nums[0] > target){
            return 0;
        }
        if(nums[r] < target){
            return r+1;
        }
        while(l<r){
            int mid = l+((r-l)/2);
            if(nums[mid] >= target){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};
// PROBLEM:- https://leetcode.com/problems/search-insert-position/description
