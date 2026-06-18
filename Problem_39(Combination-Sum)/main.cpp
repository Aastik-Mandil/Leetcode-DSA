class Solution {
    vector<vector<int>> ans;
    void solve(vector<int>& candidates, int target, int idx, vector<int> z){
        if(target == 0){
            reverse(z.begin(), z.end());
            ans.push_back(z);
            return;
        }
        if(idx == 0){
            return ;
        }
        if(target >= candidates[idx-1]){
            z.push_back(candidates[idx-1]);
            solve(candidates, target-candidates[idx-1], idx, z);
            z.pop_back();
        }
        solve(candidates, target, idx-1, z);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        vector<int> z;
        solve(candidates, target, candidates.size(), z);
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/combination-sum/description/
