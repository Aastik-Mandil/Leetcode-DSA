class Solution {
    int firstOccurance(vector<int> &nums, int target){
        int l = 0, r = nums.size()-1;
        int ans = -1;
        while(l<=r){
            int mid = l+((r-l)/2);
            if(nums[mid] == target){
                ans = mid;
                r = mid-1;
            }
            else if(nums[mid] > target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
    int lastOccurance(vector<int> &nums, int target){
        int l = 0, r = nums.size()-1;
        int ans = -1;
        while(l<=r){
            int mid = l+((r-l)/2);
            if(nums[mid] == target){
                ans = mid;
                l = mid+1;
            }
            else if(nums[mid] > target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int a = firstOccurance(nums, target);
        int b = lastOccurance(nums, target);
        return {a, b};
    }
};
// PROBLEM:- https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description
