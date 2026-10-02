class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<string, int> mp1, mp2;
        for(int i=0; i<n; i++){
            string z = to_string(grid[i][0]);
            string t = to_string(grid[0][i]);
            for(int j=1; j<n; j++){
                z += "-"+to_string(grid[i][j]);
                t += "-"+to_string(grid[j][i]);
            }
            mp1[z]++;
            mp2[t]++;
        }

        int ans = 0;
        for(auto itr=mp1.begin(); itr!=mp1.end(); itr++){
            if(mp2[itr->first] > 0){
                ans += (itr->second * mp2[itr->first]);
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/equal-row-and-column-pairs/description
