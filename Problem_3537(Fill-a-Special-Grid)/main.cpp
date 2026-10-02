class Solution {
    void solve(vector<vector<int>> &ans, int &st, int stR, int stC, int edR, int edC){
        if(stR+1 == edR && stC+1 == edC){
            ans[stR][stC] = st;
            st++;
            return;
        }
        int midR = stR + ((edR - stR) / 2);
        int midC = stC + ((edC - stC) / 2);
        // top-right
        solve(ans, st, stR, midC, midR, edC);
        // bottom-right
        solve(ans, st, midR, midC, edR, edC);
        // bottom-left
        solve(ans, st, midR, stC, edR, midC);
        // top-left
        solve(ans, st, stR, stC, midR, midC);
    }
public:
    vector<vector<int>> specialGrid(int n) {
        int st = 0;
        vector<vector<int>> ans(pow(2, n), vector<int>(pow(2,n)));
        solve(ans, st, 0, 0, pow(2, n), pow(2, n));
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/fill-a-special-grid/description/
