class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        // calculate the maximum from the list
        int maxi = nums[0];
        for(int i=1; i<n; i++){
            maxi = max(maxi, nums[i]);
        }

        // use sliding window to find the subarray
        int l = 0;
        int r = 0;
        long long ans = 0;
        while(r < n){
            if(nums[r] == maxi){
                k--;
            }
            while(k == 0){
                ans += (n-r);
                if(nums[l] == maxi){
                    k++;
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/
