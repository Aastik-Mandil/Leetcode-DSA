class Solution {
    void traverse(vector<int> &nums, int last, int idx, set<vector<int>> &res, vector<int> z){
        if(z.size()>1){
            res.insert(z);
        }
        if(idx == nums.size()){
            return;
        }
        if(last==-1 || nums[last] <= nums[idx]){
            z.push_back(nums[idx]);
            traverse(nums, idx, idx+1, res, z);
            z.pop_back();
        }
        traverse(nums, last, idx+1, res, z);
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> z;
        traverse(nums, -1, 0, res, z);
        vector<vector<int>> ans;
        for(auto itr=res.begin();itr!=res.end();itr++){
            ans.push_back(*itr);
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/non-decreasing-subsequences/description/
