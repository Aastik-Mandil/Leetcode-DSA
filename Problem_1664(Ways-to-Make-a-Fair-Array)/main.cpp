class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 1;
        }

        // prefix sum
        vector<int> prefix(n);
        prefix[0] = nums[0];
        prefix[1] = nums[1];
        for(int i=2; i<n; i++){
            prefix[i] = nums[i] + prefix[i-2];
        }
        // suffix sum
        vector<int> suffix(n);
        suffix[n-1] = nums[n-1];
        suffix[n-2] = nums[n-2];
        for(int i=n-3; i>=0; i--){
            suffix[i] = nums[i] + suffix[i+2];
        }

        // calculate the sum after removing each idx value
        int ans = 0;
        for(int i=0; i<n; i++){
            int oddIdxSum = 0, evenIdxSum = 0;
            if(i-2 >= 0){
                oddIdxSum += prefix[i-2];
            }
            if(i+1 < n){
                oddIdxSum += suffix[i+1];
            }

            if(i-1 >= 0){
                evenIdxSum += prefix[i-1];
            }
            if(i+2 < n){
                evenIdxSum += suffix[i+2];
            }
            if(oddIdxSum == evenIdxSum){
                ans++;
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/ways-to-make-a-fair-array/description/

// Example - 2 1 6 4
// 
// PrefixSum - 2 1 8 5
// SuffixSum - 8 5 6 4
// 
// idx = 0: 2 -> 5 6
// idx = 1: 1 -> 6 2+4
// idx = 2: 6 -> 2+4 1
// idx = 3: 4 -> 1 8
