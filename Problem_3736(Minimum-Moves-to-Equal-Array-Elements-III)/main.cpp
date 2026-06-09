class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = nums[0];
        for(int &num: nums){
            maxi = max(maxi, num);
        }

        int ans = 0;
        for(int &num: nums){
            ans += (maxi - num);
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/description/
