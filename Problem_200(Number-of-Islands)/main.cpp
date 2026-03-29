class Solution {
public:
    vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
    bool canMove(vector<vector<char>> &grid, int n, int m, int r, int c, vector<vector<bool>> &visited){
        return r>=0 && r<n && c>=0 && c<m && grid[r][c]=='1' && visited[r][c]==false;
    }
    void traversal(vector<vector<char>> &grid, int r, int c, vector<vector<bool>> &visited, int n, int m){
        if(!canMove(grid, n, m, r, c, visited)){
            return;
        }
        visited[r][c]=true;
        for(int i=0;i<dirs.size();i++){
            int newX = r+dirs[i][0];
            int newY = c+dirs[i][1];
            // if(canMove(grid, n, m, newX, newY, visited)){
                traversal(grid, newX, newY, visited, n, m);
            // }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='0' || visited[i][j]){
                    continue;
                }
                ans++;
                traversal(grid,i,j,visited,n,m);
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/number-of-islands/
