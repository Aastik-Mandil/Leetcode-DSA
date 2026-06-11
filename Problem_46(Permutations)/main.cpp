class Solution {
    vector<vector<int>> ans;
    void solve(int n, vector<int> &num, vector<int> z){
        if(z.size()==n){
            ans.push_back(z);
            return;
        }
        for(int i=0;i<n;i++){
            if(find(z.begin(), z.end(), num[i]) == z.end()){
                z.push_back(num[i]);
                solve(n, num, z);
                z.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> z;
        solve(n, nums, z);
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/permutations/description/
