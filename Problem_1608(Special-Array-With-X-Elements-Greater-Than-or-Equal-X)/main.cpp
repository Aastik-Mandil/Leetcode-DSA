class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i == 0){
                if(n <= nums[i]){
                    return n;
                }
            }
            else{
                int cnt = n - i;
                if(cnt > nums[i-1] && cnt <= nums[i]){
                    return cnt;
                }
            }
        }
        return -1;
    }
};
// PROBLEM:- https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/
