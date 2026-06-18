class Solution {
    vector<vector<int>> ans;
    void solve(int n, int k, vector<int> z, int last){
        if(z.size()==k){
            ans.push_back(z);
            return;
        }
        for(int i=last+1;i<=n;i++){
            if(find(z.begin(), z.end(), i) == z.end()){
                z.push_back(i);
                solve(n,k,z,i);
                z.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        if(k>n){
            return ans;
        }

        vector<int> z;
        solve(n,k,z,0);
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/combinations/description/
