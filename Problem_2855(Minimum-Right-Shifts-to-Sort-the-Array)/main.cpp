class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int miniIdx = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] < nums[miniIdx]){
                miniIdx = i;
            }
        }

        for(int i=miniIdx+1; i<(miniIdx+nums.size()); i++){
            int left = (i - 1) % nums.size();
            int right = i % nums.size();
            if(nums[left] > nums[right]){
                return -1;
            }
        }
        return (nums.size() - miniIdx) % nums.size();
    }
};
// PROBLEM:- https://leetcode.com/problems/minimum-right-shifts-to-sort-the-array/description/
