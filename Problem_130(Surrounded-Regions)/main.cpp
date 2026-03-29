class Solution {
public:
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    bool canMove(vector<vector<char>> &board, vector<vector<bool>> &visited, int n, int m, int r, int c){
        return r>=0 && r<n && c>=0 && c<m && board[r][c]=='O' && visited[r][c]==false;
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));

        queue<pair<int,int>> q;
        for(int j=0;j<m;j++){
            // top row
            if(board[0][j]=='O'){
                q.push({0,j});
                visited[0][j]=true;
            }
            // bottom row
            if(board[n-1][j]=='O'){
                q.push({n-1,j});
                visited[n-1][j]=true;
            }
        }
        for(int i=0;i<n;i++){
            // left col
            if(board[i][0]=='O'){
                q.push({i,0});
                visited[i][0]=true;
            }
            // right col
            if(board[i][m-1]=='O'){
                q.push({i,m-1});
                visited[i][m-1]=true;
            }
        }

        while(q.size()>0){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<dirs.size();i++){
                int newR = r+dirs[i][0];
                int newC = c+dirs[i][1];
                if(canMove(board, visited, n, m, newR, newC)){
                    visited[newR][newC] = true;
                    q.push({newR,newC});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]){
                    board[i][j]='O';
                }
                else{
                    board[i][j]='X';
                }
            }
        }
    }
};
// PROBLEM:- https://leetcode.com/problems/surrounded-regions/submissions/1962652948/
