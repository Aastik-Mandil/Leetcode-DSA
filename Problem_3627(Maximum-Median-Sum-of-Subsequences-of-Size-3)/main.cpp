class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        // sort the list
        sort(nums.begin(), nums.end());

        // use two pointer to find the maximum median sum
        int i = 0, j = nums.size() - 1;
        long long ans = 0;
        while(i < j){
            ans += nums[j-1];
            i++;
            j -= 2;
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/maximum-median-sum-of-subsequences-of-size-3/description/?envType=problem-list-v2&envId=sorting
