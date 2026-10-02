class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        int n = nums.size();
        if(n%2 != 0){
            return false;
        }

        unordered_map<int, int> mp;
        for(int &num: nums){
            mp[num]++;
            if(mp[num] > 2){
                return false;
            }
        }
        return true;
    }
};
// PROBLEM:- https://leetcode.com/problems/split-the-array/description/
