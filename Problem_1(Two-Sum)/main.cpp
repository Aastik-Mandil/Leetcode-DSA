class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            if(mp[target-num] > 0){
                return {mp[target-num]-1, i};
            }
            mp[num] = i+1;
        }
        return {-1, -1};
    }
};
// PROBLEM:- https://leetcode.com/problems/two-sum/description
