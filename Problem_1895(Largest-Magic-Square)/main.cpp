class Solution {
    bool isMagicSquare(vector<vector<int>>& grid, int stR, int stC, int edR, int edC){
        int total = 0;
        for(int i=stR; i<edR; i++){
            total += grid[i][stC];
        }
        for(int i=stR; i<edR; i++){
            int count = 0;
            for(int j=stC; j<edC; j++){
                count += grid[i][j];
            }
            if(total != count){
                return false;
            }
        }
        for(int j=stC; j<edC; j++){
            int count = 0;
            for(int i=stR; i<edR; i++){
                count += grid[i][j];
            }
            if(total != count){
                return false;
            }
        }
        int count1 = 0, count2 = 0;
        for(int i=0; i<(edR-stR); i++){
            count1 += grid[stR+i][stC+i];
            count2 += grid[stR+i][edC-i-1];
        }
        return count1 == total && count2 == total;
    }
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        if(n == 1 || m == 1){
            return 1;
        }
        for(int i=0; i<=(n-1); i++){
            for(int j=0; j<=(m-1); j++){
                for(int k = ans+1; k<=max(n, m) && i+k <= n && j+k <= m; k++){
                    if(isMagicSquare(grid, i, j, i+k, j+k)){
                        ans = max(ans, k);
                    }
                }
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/largest-magic-square/description/
