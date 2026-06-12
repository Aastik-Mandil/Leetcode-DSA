class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int stR = x, edR = x+k-1;
        int stC = y, edC = y+k-1;
        while(stR < edR){
            for(int j=stC; j<=edC; j++){
                int temp = grid[stR][j];
                grid[stR][j] = grid[edR][j];
                grid[edR][j] = temp;
            }
            stR++;
            edR--;
        }
        return grid;
    }
};
// PROBLEM:-https://leetcode.com/problems/flip-square-submatrix-vertically/description/
