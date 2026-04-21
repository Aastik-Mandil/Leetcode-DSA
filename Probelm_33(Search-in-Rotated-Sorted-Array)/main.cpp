class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l<=r){
            int mid = l+((r-l)/2);
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] >= nums[l]){
                if(target >= nums[l] && target < nums[mid]){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            else{
                if(target > nums[mid] && target<=nums[r]){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
        }
        if(l==r && nums[l] == target){
            return l;
        }
        return -1;
    }
};
// PROBLEM:- https://leetcode.com/problems/search-in-rotated-sorted-array/description
