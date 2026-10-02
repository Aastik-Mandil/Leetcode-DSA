class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int,int> mp;
        for(int i=nums.size()-1; i>=0; i--){
            int num = nums[i];
            count++;
            if(num > k){
                continue;
            }
            mp[num] = 1;
            if(mp.size() == k){
                return count;
            }
        }
        return count;
    }
};
// PROBLEM:- https://leetcode.com/problems/minimum-operations-to-collect-elements/description/
