class Solution {
    int getSum(vector<vector<int>>& mat, int n, int m, int stR, int edR, int stC, int edC){
        int total = 0;
        for(int i=max(0, stR); i<=min(edR, n-1); i++){
            for(int j=max(0, stC); j<=min(edC, m-1); j++){
                total += mat[i][j];
            }
        }
        return total;
    }

    vector<vector<int>> solveB(vector<vector<int>>& mat, int k){
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans[i][j] = getSum(mat, n, m, i-k, i+k, j-k, j+k);
            }
        }
        return ans;
    }
    vector<vector<int>> solveO(vector<vector<int>>& mat, int k){
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> pre(n, vector<int>(m, 0));
        pre[0][0] = mat[0][0];
        for(int i=1; i<n; i++){
            pre[i][0] = mat[i][0] + pre[i-1][0];
        }
        for(int j=1; j<m; j++){
            pre[0][j] = mat[0][j] + pre[0][j-1];
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                pre[i][j] = (mat[i][j] + pre[i][j-1] + pre[i-1][j] - pre[i-1][j-1]);
            }
        }

        vector<vector<int>> ans(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int val = pre[min(i+k, n-1)][min(j+k, m-1)];
                if(i-k > 0){
                    val -= pre[i-k-1][min(j+k, m-1)];
                }
                if(j-k > 0){
                    val -= pre[min(i+k, n-1)][j-k-1];
                }
                if(i-k > 0 && j-k > 0){
                    val += pre[i-k-1][j-k-1];
                }
                ans[i][j] = val;
            }
        }
        return ans;
    }
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        // return solveB(mat, k);

        return solveO(mat, k);
    }
};
// PROBLEM:- https://leetcode.com/problems/matrix-block-sum/description/
