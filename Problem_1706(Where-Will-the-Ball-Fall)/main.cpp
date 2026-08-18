class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid[0].size(), m = grid.size();

        if(n == 1){
            return {-1};
        }

        vector<pair<int, int>> v(n);
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++){
            v[i] = {0, i};
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(ans[j] != 0){
                    continue;
                }
                int x = v[j].first;
                int y = v[j].second;
                if(grid[x][y] == 1){
                    if(y+1 == n || grid[x][y+1] == -1){
                        ans[j] = -1;
                    }
                    else{
                        v[j] = {v[j].first+1, v[j].second+1};
                    }
                }
                else{
                    if(y-1 < 0 || grid[x][y-1] == 1){
                        ans[j] = -1;
                    }
                    else{
                        v[j] = {v[j].first+1, v[j].second-1};
                    }
                }
            }
        }

        for(int i=0; i<n; i++){
            if(ans[i] == -1){
                continue;
            }
            ans[i] = v[i].second;
        }

        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/where-will-the-ball-fall/description/
