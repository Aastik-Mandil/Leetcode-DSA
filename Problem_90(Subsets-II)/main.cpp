class Solution {
    vector<vector<int>> ans;
    void solve(vector<int> &nums, int idx, vector<int> z){
        ans.push_back(z);
        if(idx == nums.size()){
            return;
        }
        unordered_set<int> st;
        for(int i=idx; i<nums.size(); i++){
            if(st.find(nums[i]) == st.end()){
                st.insert(nums[i]);
                z.push_back(nums[i]);
                solve(nums, i+1, z);
                z.pop_back();
            }
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ans.clear();
        vector<int> z;
        solve(nums, 0, z);
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/subsets-ii/description/
