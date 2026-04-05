class Solution {
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    bool canMove(int n,int m,int r,int c){
        return r>=0 && r<n && c>=0 && c<m;
    }
    bool traverse(vector<vector<char>> &board,int idx,string word,int n,int m,int r,int c){
        if(idx==word.size()){
            return true;
        }
        if(!canMove(n,m,r,c)){
            return false;
        }
        if(board[r][c]!=word[idx]){
            return false;
        }
        char ch = board[r][c];
        board[r][c] = '#';
        for(int i=0;i<4;i++){
            int newR = r+dx[i];
            int newC = c+dy[i];
            if(traverse(board,idx+1,word,n,m,newR,newC)){
                return true;
            }
        }
        board[r][c] = ch;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(traverse(board,0,word,n,m,i,j)){
                    return true;
                }
            }
        }
        return false;
    }
};
// PROBLEM:- https://leetcode.com/problems/word-search/
