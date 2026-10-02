class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> v1(n), v2(n);
        v1[0] = nums[0];
        v2[n-1] = nums[n-1];
        for(int i=1; i<n; i++){
            v1[i] = min(v1[i-1], nums[i]);
        }
        for(int i=n-2; i>=0; i--){
            v2[i] = min(v2[i+1], nums[i]);
        }

        int ans = INT_MAX;
        for(int i=1; i<(n-1); i++){
            if(nums[i] > v1[i-1] && nums[i] > v2[i+1]){
                ans = min(ans, v1[i-1] + nums[i] + v2[i+1]);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/minimum-sum-of-mountain-triplets-i/description/
