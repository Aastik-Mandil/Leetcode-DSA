class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size(), m = boxGrid[0].size();
        vector<vector<char>> ans(m, vector<char>(n, '.'));
        int x = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans[i][j] = boxGrid[n-1-j][x];
            }
            x++;
        }

        for(int j=0; j<ans[0].size(); j++){
            int space = -1; 
            for(int i=ans.size()-1; i>=0; i--){
                if(ans[i][j] == '*'){
                    space = -1;
                }
                else if(ans[i][j] == '#'){
                    if(space != -1){
                        ans[space][j] = ans[i][j];
                        ans[i][j] = '.';
                        space--;
                    }
                }
                else{
                    if(space == -1){
                        space = i;
                    }
                }
            }
        }

        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/rotating-the-box/description/
