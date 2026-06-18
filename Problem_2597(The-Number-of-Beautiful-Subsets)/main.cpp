class Solution {
    int ans = 0;
public:
    void solve(vector<int> &nums,int idx,int k,unordered_map<int,int> &mp){
        if(mp.size() > 0){
            ans++;
        }
        if(idx==nums.size()){
            return;
        }
        for(int i=idx;i<nums.size();i++){
            if(mp[nums[i]-k] == 0 && mp[nums[i]+k] == 0){
                mp[nums[i]]++;
                solve(nums,i+1,k,mp);
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
            }
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        solve(nums,0,k,mp);
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/the-number-of-beautiful-subsets/description/
