class Solution {
    vector<int> dr = {0,1,0,-1};
    vector<int> dc = {1,0,-1,0};
    int getGold(vector<vector<int>> &grid, int n, int m, int r, int c){
        if(r<0 || c<0 || r>=n || c>=m){
            return 0;
        }
        if(grid[r][c] == 0){
            return 0;
        }
        int val = grid[r][c];
        grid[r][c] = 0;
        int total = 0;
        for(int i=0;i<4;i++){
            total = max(total, val+getGold(grid, n, m, r+dr[i], c+dc[i]));
        }
        grid[r][c] = val;
        return total;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    ans=max(ans, getGold(grid, n, m, i, j));
                }
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/path-with-maximum-gold/description/
