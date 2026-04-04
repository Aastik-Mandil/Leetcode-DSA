class Solution {
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    bool isValid(vector<vector<int>> &grid, int n, int m, int r, int c){
        return r>=0 && r<n && c>=0 && c<m && grid[r][c] != -1;
    }
    bool isSatistyCond(vector<vector<int>> &grid, int n, int m){
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==-1){
                    count++;
                }
            }
        }
        return count == (n*m)-1;
    }
    int canReach(vector<vector<int>> &grid, int n, int m, int r, int c){
        if(!isValid(grid, n, m, r, c)){
            return 0;
        }
        if(grid[r][c]==2){
            if(isSatistyCond(grid, n, m)){
                return 1;
            }
            return 0;
        }
        int val = grid[r][c];
        grid[r][c] = -1;
        int count = 0;
        for(int i=0;i<4;i++){
            int newR = r+dx[i];
            int newC = c+dy[i];
            count += canReach(grid, n, m, newR, newC);
        }
        grid[r][c] = val;
        return count;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    count += canReach(grid, n, m, i, j);
                }
            }
        }
        return count;
    }
};
// PROBLEM:- https://leetcode.com/problems/unique-paths-iii/description/
