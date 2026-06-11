class Solution {
    bool canFill(vector<vector<char>> &board, int r, int c, char val){
        for(int i=0;i<9;i++){
            if(board[i][c] == val){
                return false;
            }
            if(board[r][i] == val){
                return false;
            }
        }
        int stR = r-(r%3);
        int stC = c-(c%3);
        for(int i=stR;i<stR+3;i++){
            for(int j=stC;j<stC+3;j++){
                if(board[i][j] == val){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> &board, int r, int c){
        if(r==9){
            return true;
        }
        if(c==9){
            return solve(board, r+1, 0);
        }
        if(board[r][c] != '.'){
            return solve(board, r, c+1);
        }
        for(char i='1';i<='9';i++){
            if(canFill(board, r, c, i)){
                board[r][c] = i;
                if(solve(board, r, c+1)){
                    return true;
                }
                board[r][c] = '.';
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};
// PROBLEM:- https://leetcode.com/problems/sudoku-solver/description/
