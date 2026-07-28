class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        // row palindrome
        int count1 = 0;
        for(int i=0; i<n; i++){
            int st = 0, ed = m-1;
            while(st<ed){
                if(grid[i][st] != grid[i][ed]){
                    count1++;
                }
                st++;
                ed--;
            }
        }

        // col palindrome
        int count2 = 0;
        for(int j=0; j<m; j++){
            int st = 0, ed = n-1;
            while(st<ed){
                if(grid[st][j] != grid[ed][j]){
                    count2++;
                }
                st++;
                ed--;
            }
        }
        return min(count1, count2);
    }
};
// PROBLEM:- https://leetcode.com/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-i/description/
