class Solution {
    vector<vector<int>> ans;
    void solve(int k, int target, int last, vector<int> z){
        if(target == 0){
            if(k == 0){
                ans.push_back(z);
            }
            return;
        }
        for(int i=last+1;i<=9;i++){
            if(target >= i){
                z.push_back(i);
                solve(k-1, target-i, i, z);
                z.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear();
        vector<int> z;
        solve(k, n, 0, z);
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/combination-sum-iii/description/
