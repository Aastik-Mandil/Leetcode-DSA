class Solution {
    vector<vector<int>> ans;
    void solve(vector<int> &nums, vector<int> z, vector<int> included){
        if(z.size() == nums.size()){
            ans.push_back(z);
            return;
        }
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i]) == st.end() && find(included.begin(), included.end(), i) == included.end()){
                st.insert(nums[i]);
                included.push_back(i);
                z.push_back(nums[i]);
                solve(nums, z, included);
                included.pop_back();
                z.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ans.clear();
        vector<int> z;
        vector<int> included;
        solve(nums, z, included);
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/permutations-ii/description/
