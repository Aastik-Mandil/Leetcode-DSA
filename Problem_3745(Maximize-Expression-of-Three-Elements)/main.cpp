class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int miniIdx = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[miniIdx] > nums[i]){
                miniIdx = i;
            }
        }

        int maxiIdx = 0, maxiIdx2 = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[maxiIdx] < nums[i]){
                maxiIdx2 = maxiIdx;
                maxiIdx = i;
            }
            else if(nums[maxiIdx2] < nums[i]){
                maxiIdx2 = i;
            }
        }

        return nums[maxiIdx] + nums[maxiIdx2] - nums[miniIdx];
    }
};
// PROBLEM:- https://leetcode.com/problems/maximize-expression-of-three-elements/description/
