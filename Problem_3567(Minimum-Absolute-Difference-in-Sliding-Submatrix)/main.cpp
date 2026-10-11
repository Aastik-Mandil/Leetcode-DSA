class Solution {
    int findDifference(vector<vector<int>>& grid, int r, int c, int k){
        // store the k*k size into a list
        vector<int> v;
        for(int i=r; i<(r+k); i++){
            for(int j=c; j<(c+k); j++){
                v.push_back(grid[i][j]);
            }
        }
        
        // sort them
        sort(v.begin(), v.end());

        // not calculate the minimum value from consecutive difference for distinct character
        int ans = INT_MAX;
        for(int i=1; i<v.size(); i++){
            if(v[i] == v[i-1]){
                continue;
            }
            ans = min(ans, abs(v[i] - v[i-1]));
        }
        return ans == INT_MAX ? 0 : ans;
    }
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n-k+1, vector<int>(m-k+1, 0));
        if(k == 1){
            return ans;
        }

        for(int i=0; i<(n-k+1); i++){
            for(int j=0; j<(m-k+1); j++){
                ans[i][j] = findDifference(grid, i, j, k);
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/description/
