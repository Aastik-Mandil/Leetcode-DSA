class Solution {
    vector<vector<int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    bool isValid(vector<vector<int>>& board, int r, int c){
        int n = board.size(), m = board[0].size();
        return r>=0 && r<n && c>=0 && c<m;
    }
    int getAliveNeighbour(vector<vector<int>>& board, int r, int c){
        int total = 0;
        for(vector<int> &dir: dirs){
            int newR = r+dir[0];
            int newC = c+dir[1];
            if(isValid(board, newR, newC) && board[newR][newC] == 1){
                total++;
            }
        }
        return total;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> temp(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int nbr = getAliveNeighbour(board, i, j);
                if(board[i][j] == 1 && (nbr == 2 || nbr == 3)){
                    temp[i][j] = 1;
                }
                else if(board[i][j] == 0 && nbr == 3){
                    temp[i][j] = 1;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j] = temp[i][j];
            }
        }
    }
};
// PROBLEM:- https://leetcode.com/problems/game-of-life/description
