class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=1; i<nums.size(); i++){
            int val = nums[i-1] + nums[i];
            mp[val]++;
            if(mp[val] == 2){
                return true;
            }
        }
        return false;
    }
};
// PROBLEM:- https://leetcode.com/problems/find-subarrays-with-equal-sum/description/
