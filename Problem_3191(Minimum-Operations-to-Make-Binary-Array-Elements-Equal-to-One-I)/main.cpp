class Solution {
public:
    int minOperations(vector<int>& nums) {
        int idx = 0;
        int count = 0;
        while(idx < nums.size()){
            while(idx<nums.size() && nums[idx] == 1){
                idx++;
            }
            if(idx < nums.size()-2){
                count++;
                nums[idx] ^= 1;
                nums[idx+1] ^= 1;
                nums[idx+2] ^= 1;
                idx++;
            }
            else{
                break;
            }
        }
        if(idx >= nums.size()){
            return count;
        }
        return -1;
    }
};
// PROBLEM:- https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/description/
