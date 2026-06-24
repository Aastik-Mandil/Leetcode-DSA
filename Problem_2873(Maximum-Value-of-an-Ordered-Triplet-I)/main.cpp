class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = LONG_MIN;
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    long long val = (nums[i] - nums[j]);
                    ans = max(ans, val * nums[k]);
                }
            }
        }
        return ans < 0 ? 0 : ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/description/
