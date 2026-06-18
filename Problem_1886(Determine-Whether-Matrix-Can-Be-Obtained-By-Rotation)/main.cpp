class Solution {
    void rotate(vector<vector<int>> &mat){
        int n = mat.size();
        // transport
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int val = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = val;
            }
        }

        // reverse each row
        for(int i=0;i<n;i++){
            reverse(mat[i].begin(), mat[i].end());
        }
    }
    bool isMatched(vector<vector<int>>& mat, vector<vector<int>>& target){
        int n = mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] != target[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i=0;i<4;i++){
            rotate(mat);
            if(isMatched(mat, target)){
                return true;
            }
        }
        return false;
    }
};
// PROBLEM:- https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/description/
