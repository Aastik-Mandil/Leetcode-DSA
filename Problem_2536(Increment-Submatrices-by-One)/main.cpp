class Solution {
    vector<vector<int>> solveB(int n, vector<vector<int>>& queries){
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(vector<int> &query: queries){
            int r1 = query[0];
            int c1 = query[1];
            int r2 = query[2];
            int c2 = query[3];
            for(int i=r1; i<=r2; i++){
                for(int j=c1; j<=c2; j++){
                    v[i][j]++;
                }
            }
        }
        return v;
    }
    vector<vector<int>> solveO(int n, vector<vector<int>>& queries){
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(vector<int> &query: queries){
            int r1 = query[0];
            int c1 = query[1];
            int r2 = query[2];
            int c2 = query[3];
            for(int i=r1; i<=r2; i++){
                v[i][c1]++;
                if(c2+1 < n){
                    v[i][c2+1]--;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=1; j<n; j++){
                v[i][j] += v[i][j-1];
            }
        }
        return v;
    }
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        // return solveB(n, queries);

        return solveO(n, queries);
    }
};
// PROBLEM:- https://leetcode.com/problems/increment-submatrices-by-one/description/
