class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=n-3; i>=0; i--){
            int maxi = nums[i+1] + nums[i];
            int mini = nums[i+1] - nums[i];
            if(nums[i+2] < maxi && nums[i+2] > mini){
                return maxi + nums[i+2];
            }
        }
        return 0;
    }
};
// PROBLEM:- https://leetcode.com/problems/largest-perimeter-triangle/description/
