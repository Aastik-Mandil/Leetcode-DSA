class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> oddIdx;
        int ans = 0;
        int l = 0, r = 0;
        while(r<nums.size()){
            if(nums[r]%2 != 0){
                oddIdx.push_back(r);
            }
            if(oddIdx.size() > k){
                l = oddIdx[0]+1;
                oddIdx.erase(oddIdx.begin());
            }
            if(oddIdx.size() == k){
                ans += (oddIdx[0]-l+1);
            }
            r++;
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/count-number-of-nice-subarrays/description/
