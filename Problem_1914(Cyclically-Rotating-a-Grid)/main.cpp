typedef pair<int, int> P;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> ans(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans[i][j] = grid[i][j];
            }
        }

        int stR = 0;
        int stC = 0;
        int edR = n-1;
        int edC = m-1;
        vector<vector<P>> temp;
        while(stR<=edR && stC<=edC){
            vector<P> v;
            // left -> right (i = stR)
            if(stC <= edC){
                for(int j=stC; j<=edC; j++){
                    v.push_back({stR, j});
                }
                stR++;
            }
            // top -> bottom (j = edC)
            if(stR <= edR){
                for(int i=stR; i<=edR; i++){
                    v.push_back({i, edC});
                }
                edC--;
            }
            // right -> left (i = edR)
            if(stC <= edC){
                for(int j=edC; j>=stC; j--){
                    v.push_back({edR, j});
                }
                edR--;
            }
            // bottom -> top (j = stC)
            if(stR <= edR){
                for(int i=edR; i>=stR; i--){
                    v.push_back({i, stC});
                }
                stC++;
            }
            temp.push_back(v);
        }

        for(vector<P> &t: temp){
            int n = k % t.size();
            for(int i=0; i<t.size(); i++){
                int r = t[i].first;
                int c = t[i].second;
                int x = t[(i+n) % t.size()].first;
                int y = t[(i+n) % t.size()].second;
                ans[r][c] = grid[x][y];
            }
        }

        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/cyclically-rotating-a-grid/description/
