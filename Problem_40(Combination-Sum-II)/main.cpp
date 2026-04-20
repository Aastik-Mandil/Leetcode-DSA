class Solution {
    vector<vector<int>> ans;
    void solveR(vector<int> &nums, int idx, int target, vector<int> z){
        if(target == 0){
            ans.push_back(z);
            return;
        }
        if(idx == nums.size()){
            return;
        }
        unordered_set<int> st;
        for(int i=idx; i<nums.size() && target>=nums[i]; i++){
            if(st.find(nums[i]) == st.end()){
                st.insert(nums[i]);
                z.push_back(nums[i]);
                solveR(nums, i+1, target-nums[i], z);
                z.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        ans.clear();
        vector<int> z;

        solveR(nums, 0, target, z);

        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/combination-sum-ii/description/
