class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int &num: nums){
            mp[num]++;
        }

        vector<int> ans;
        for(int &num: nums){
            if(mp[num] == 1 && mp[num-1] == 0 && mp[num+1] == 0){
                ans.push_back(num);
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/description/
