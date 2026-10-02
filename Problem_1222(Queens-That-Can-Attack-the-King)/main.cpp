class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        unordered_map<int, unordered_map<int, bool>> mp;
        for(vector<int> &queen: queens){
            int r = queen[0];
            int c = queen[1];
            mp[r][c] = true;
        }

        vector<vector<int>> ans;
        int r, c;
        // top
        r = king[0]-1, c = king[1];
        for(int i=r; i>=0; i--){
            if(mp[i][c]){
                ans.push_back({i, c});
                break;
            }
        }
        // right
        r = king[0], c = king[1]+1;
        for(int j=c; j<8; j++){
            if(mp[r][j]){
                ans.push_back({r, j});
                break;
            }
        }
        // bottom
        r = king[0]+1, c = king[1];
        for(int i=r; i<8; i++){
            if(mp[i][c]){
                ans.push_back({i, c});
                break;
            }
        }
        // left
        r = king[0], c = king[1]-1;
        for(int j=c; j>=0; j--){
            if(mp[r][j]){
                ans.push_back({r, j});
                break;
            }
        }
        // top-right
        r = king[0]-1, c = king[1]+1;
        for(int i=r, j=c; i>=0 && j<8; i--, j++){
            if(mp[i][j]){
                ans.push_back({i, j});
                break;
            }
        }
        // bottom-right
        r = king[0]+1, c = king[1]+1;
        for(int i=r, j=c; i<8 && j<8; i++, j++){
            if(mp[i][j]){
                ans.push_back({i, j});
                break;
            }
        }
        // bottom-left
        r = king[0]+1, c = king[1]-1;
        for(int i=r, j=c; i<8 && j>=0; i++, j--){
            if(mp[i][j]){
                ans.push_back({i, j});
                break;
            }
        }
        // top-left
        r = king[0]-1, c = king[1]-1;
        for(int i=r, j=c; i>=0 && j>=0; i--, j--){
            if(mp[i][j]){
                ans.push_back({i, j});
                break;
            }
        }

        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/queens-that-can-attack-the-king/description/
