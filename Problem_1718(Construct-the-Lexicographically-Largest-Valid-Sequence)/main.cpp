class Solution {
    bool solve(int n, int idx, vector<int> &ans, vector<bool> &used){
        if(idx >= ans.size()){
            return true;
        }
        if(ans[idx] != -1){
            return solve(n, idx+1, ans, used);
        }
        for(int i=n;i>=1;i--){
            if(used[i]){
                continue;
            }
            if(i==1){
                used[i] = true;
                ans[idx] = i;
                if(solve(n, idx+1, ans, used)){
                    return true;
                }
                used[i] = false;
                ans[idx] = -1;
            }
            else{
                if(idx+i >= ans.size() || ans[idx+i] != -1){
                    continue;
                }
                used[i] = true;
                ans[idx] = i;
                ans[idx + i] = i;
                if(solve(n, idx+1, ans, used)){
                    return true;
                }
                used[i] = false;
                ans[idx] = -1;
                ans[idx + i] = -1;
            }
        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n - 1, -1);
        vector<bool> used(n+1, false);
        solve(n, 0, ans, used);
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/description/
