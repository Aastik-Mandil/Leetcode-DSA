class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l<=r){
            int mid = l + ((r-l)/2);
            cout<<l<<" "<<r<<" "<<mid<<endl;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] >= nums[l]){
                if(nums[l] <= target && nums[mid] >= target){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            else{
                if(nums[mid] <= target && nums[r] >= target){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
        }
        return -1;
    }
};
// PROBLEM:- https://leetcode.com/problems/search-in-rotated-sorted-array/description/
