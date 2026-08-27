class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                mp[nums[i]*nums[j]]++;
            }
        }

        int ans = 0;
        for(auto itr=mp.begin(); itr!=mp.end(); itr++){
            int val = itr->second;
            ans += ((val * (val-1)) * 4);
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/tuple-with-same-product/description/
