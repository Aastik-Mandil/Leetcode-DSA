class Solution {
    int ans;
    bool canPlace(vector<string> board, int r, int c, int n){
        for(int i=0;i<n;i++){
            if(board[i][c] == 'Q'){
                return false;
            }
            if(board[r][i] == 'Q'){
                return false;
            }
        }
        // top-left
        int r1 = r, c1 = c;
        while(r1>=0 && r1<n && c1>=0 && c1<n){
            if(board[r1][c1] == 'Q'){
                return false;
            }
            r1--;
            c1--;
        }
        // top-right
        r1 = r;
        c1 = c;
        while(r1>=0 && r1<n && c1>=0 && c1<n){
            if(board[r1][c1] == 'Q'){
                return false;
            }
            r1--;
            c1++;
        }
        // bottom-left
        r1 = r;
        c1 = c;
        while(r1>=0 && r1<n && c1>=0 && c1<n){
            if(board[r1][c1] == 'Q'){
                return false;
            }
            r1++;
            c1--;
        }
        // bottom-right
        r1 = r;
        c1 = c;
        while(r1>=0 && r1<n && c1>=0 && c1<n){
            if(board[r1][c1] == 'Q'){
                return false;
            }
            r1++;
            c1++;
        }
        return true;
    }
    void solve(int n, int r, int N, vector<string> board){
        if(n == 0){
            ans++;
            return;
        }
        for(int c=0;c<N;c++){
            if(canPlace(board,r,c,N)){
                board[r][c] = 'Q';
                solve(n-1, r+1, N, board);
                board[r][c] = '.';
            }
        }
    }
public:
    int totalNQueens(int n) {
        ans = 0;
        vector<string> board;
        for(int i=0;i<n;i++){
            string t="";
            for(int j=0;j<n;j++){
                t.push_back('.');
            }
            board.push_back(t);
        }
        solve(n, 0, n, board);
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/n-queens-ii/description/
