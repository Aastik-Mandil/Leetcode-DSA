class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        // map the value with the {row, col}
        unordered_map<int, pair<int,int>> mp;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mp[mat[i][j]] = {i, j};
            }
        }

        vector<int> row(n, 0); // maintain the row count with get painted
        vector<int> col(m, 0); // maintain the col count with get painted
        for(int i=0; i<arr.size(); i++){
            int r = mp[arr[i]].first;
            int c = mp[arr[i]].second;
            row[r]++;
            col[c]++;
            if(row[r] == m || col[c] == n){
                return i;
            }
        }
        return arr.size()-1;
    }
};
// PROBLEM:- https://leetcode.com/problems/first-completely-painted-row-or-column/description/
