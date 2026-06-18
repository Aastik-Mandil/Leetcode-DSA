class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        for(int i=1;i<n;i++){
            if(nums[i] <= nums[idx]){
                idx = i;
            }
        }

        while(idx>0 && nums[idx]==nums[idx-1]){
            idx--;
        }

        int last = nums[idx];
        for(int i=1;i<n;i++){
            if(nums[(idx+i)%n] >= last){
                last = nums[(idx+i)%n];
            }
            else{
                return false;
            }
        }
        return true;
    }
};
// PROBLEM:- https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
