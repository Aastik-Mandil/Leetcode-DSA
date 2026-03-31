class Solution {
public:
    vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
    bool canMove(
        vector<vector<int>> &grid, int n, int m, int r, int c, vector<vector<bool>> &visited,
        int oldColor
    ){
        return r>=0 && r<n && c>=0 && c<m && grid[r][c]==oldColor && visited[r][c]==false;
    }
    void traversal(
        vector<vector<int>> &grid, int n, int m, int r, int c, vector<vector<bool>> &visited,
        int oldColor, int newColor
    ){
        if(!canMove(grid, n, m, r, c, visited, oldColor)){
            return;
        }
        visited[r][c]=true;
        grid[r][c]=newColor;
        for(int i=0;i<dirs.size();i++){
            int newX = r+dirs[i][0];
            int newY = c+dirs[i][1];
            traversal(grid, n, m, newX, newY, visited, oldColor, newColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(),m=image[0].size();
        int oldColor=image[sr][sc];
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        traversal(image,n,m,sr,sc,visited,oldColor,color);
        return image;
    }
};
// PROBLEM:- https://leetcode.com/problems/flood-fill/
