class Solution {
    bool canPlace(vector<vector<char>>& board, int r, int c, char ch){
        // row
        for(int j=0; j<board[0].size(); j++){
            if(j != c && board[r][j] == ch){
                return false;
            }
        }
        // col
        for(int i=0; i<board.size(); i++){
            if(i != r && board[i][c] == ch){
                return false;
            }
        }
        // 3x3 box
        int stR = r - r%3;
        int stC = c - c%3;
        for(int i=stR; i<(stR+3); i++){
            for(int j=stC; j<(stC+3); j++){
                if(i!= r && j!=c && board[i][j] == ch){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board, int n, int m, int r, int c){
        if(r == n){
            return true;
        }
        if(c == m){
            return solve(board, n, m, r+1, 0);
        }
        if(board[r][c] == '.'){
            return solve(board, n, m, r, c+1);
        }
        if(canPlace(board, r, c, board[r][c])){
            if(solve(board, n, m, r, c+1)){
                return true;
            }
        }
        return false;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        return solve(board, n, m, 0, 0);
    }
};
// PROBLEM:- https://leetcode.com/problems/valid-sudoku/description
