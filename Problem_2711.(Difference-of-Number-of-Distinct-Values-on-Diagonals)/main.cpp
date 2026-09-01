class Solution {
    int leftAboveDistinctCount(vector<vector<int>> &grid, int x, int y){
        int i = x-1, j = y-1;
        unordered_set<int> st;
        while(i>=0 && j>=0){
            st.insert(grid[i][j]);
            i--;
            j--;
        }
        return st.size();
    }
    int rightBelowDistinctCount(vector<vector<int>> &grid, int x, int y, int n, int m){
        int i = x+1, j = y+1;
        unordered_set<int> st;
        while(i<n && j<m){
            st.insert(grid[i][j]);
            i++;
            j++;
        }
        return st.size();
    }
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int countLA = leftAboveDistinctCount(grid, i, j);
                int countRB = rightBelowDistinctCount(grid, i, j, n, m);
                ans[i][j] = abs(countLA - countRB);
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/difference-of-number-of-distinct-values-on-diagonals/description/
