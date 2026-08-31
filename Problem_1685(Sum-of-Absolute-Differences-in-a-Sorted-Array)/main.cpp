class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        for(int i=1; i<n; i++){
            nums[i] += nums[i-1];
        }

        vector<int> ans(n, 0);
        for(int i=0; i<n; i++){
            int leftSum = 0;
            if(i-1 >= 0){
                leftSum = nums[i-1] - (i * (nums[i] - nums[i-1]));
            }
            int rightSum = (nums[n-1] - nums[i]);
            if(i-1 >= 0){
                rightSum -= ((n-1-i) * (nums[i] - nums[i-1]));
            }
            else{
                rightSum -= ((n-1-i) * nums[i]);
            }
            ans[i] = abs(leftSum) + rightSum;
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/description/
