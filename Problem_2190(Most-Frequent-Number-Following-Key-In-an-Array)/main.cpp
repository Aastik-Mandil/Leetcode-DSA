class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int,int> mp;
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1] == key){
                mp[nums[i]]++;
            }
        }
        int ans = -1;
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            if(mp[ans] < itr->second){
                ans = itr->first;
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/description/
