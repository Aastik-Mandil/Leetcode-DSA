class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        for(int i=1; i<n; i++){
            grid[i][0] += grid[i-1][0];
        }
        for(int j=1; j<m; j++){
            grid[0][j] += grid[0][j-1];
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                grid[i][j] += (grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1]);
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            if(grid[i][0] > k){
                break;
            }
            for(int j=0; j<m; j++){
                if(grid[i][j] > k){
                    break;
                }
                ans++;
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/description/
