class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int n = land.size(), m = land[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(land[i][j] != 1){
                    continue;
                }

                int r = i, c = j;
                while(r+1 < n && land[r+1][c] == 1){
                    r++;
                }
                while(c+1 < m && land[r][c+1] == 1){
                    c++;
                }

                // make all to -1
                for(int x=i; x<=r; x++){
                    for(int y=j; y<=c; y++){
                        land[x][y] = -1;
                    }
                }
                ans.push_back({i, j, r, c});
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/find-all-groups-of-farmland/description/
