int mod = 1e9 + 7;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // calculate prefix sum
        for(int i=1; i<n; i++){
            nums[i] += nums[i-1];
        }

        // calculate all the range sum and sort them
        vector<int> v;
        for(int i=0; i<n; i++){
            v.push_back(nums[i]);
            for(int j=i+1; j<n; j++){
                v.push_back(nums[j] - nums[i]);
            }
        }
        sort(v.begin(), v.end());
        
        // calculate the answer based on the range
        long long ans = 0;
        for(int i=left-1; i<right; i++){
            ans += v[i];
            ans %= mod;
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/
