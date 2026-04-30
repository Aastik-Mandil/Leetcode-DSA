class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int count = 0;
        for(int &num: nums){
            if(mp[k-num] > 0){
                mp[k-num]--;
                if(mp[k-num] == 0){
                    mp.erase(k-num);
                }
                count++;
            }
            else{
                mp[num]++;
            }
        }
        return count;
    }
};
// PROBLEM:- https://leetcode.com/problems/max-number-of-k-sum-pairs/description
