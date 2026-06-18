class Solution {
    void solveBF(vector<vector<int>> &matrix) {
        int n = matrix.size();
        vector<vector<int>> temp(n,vector<int>(n));
        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                temp[y][n-1-x] = matrix[x][y];
            }
        }
        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                matrix[x][y] = temp[x][y];
            }
        }
    }
    void solveO(vector<vector<int>> &matrix){
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int val = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = val;
            }
        }
        for(int i=0;i<n;i++){
            int st=0,ed=n-1;
            while(st<ed){
                int val = matrix[i][st];
                matrix[i][st] = matrix[i][ed];
                matrix[i][ed] = val;
                st++;
                ed--;
            }
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        // solveBF(matrix);

        solveO(matrix);
    }
};
// PROBLEM:- https://leetcode.com/problems/rotate-image/description/
