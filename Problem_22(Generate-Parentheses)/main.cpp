class Solution {
    vector<string> ans;
    void solve(int n, int count, string z){
        if(n == 0 && count == 0){
            ans.push_back(z);
            return;
        }
        if(n == 0){
            solve(n, count-1, z+")");
            return;
        }
        if(count == 0){
            solve(n-1, count+1, z+"(");
            return;
        }
        solve(n-1, count+1, z+"(");
        solve(n, count-1, z+")");
    }
public:
    vector<string> generateParenthesis(int n) {
        ans.clear();
        string z = "";
        int count = 0;
        solve(n, count, z);
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/generate-parentheses/description/
