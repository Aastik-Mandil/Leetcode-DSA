class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int stR = 0, stC = 0, edR = matrix.size()-1, edC = matrix[0].size()-1;
        vector<int> ans;
        while(stR<=edR || stC<=edC){
            // left->right (stR)
            for(int j=stC; j<=edC; j++){
                ans.push_back(matrix[stR][j]);
            }
            if(stC <= edC){
                stR++;
            }
            else{
                break;
            }

            // top->bottom (edC)
            for(int i=stR; i<=edR; i++){
                ans.push_back(matrix[i][edC]);
            }
            if(stR <= edR){
                edC--;
            }
            else{
                break;
            }

            // right->left (edR)
            for(int j=edC; j>=stC; j--){
                ans.push_back(matrix[edR][j]);
            }
            if(stC <= edC){
                edR--;
            }
            else{
                break;
            }

            // bottom->top (stC)
            for(int i=edR; i>=stR; i--){
                ans.push_back(matrix[i][stC]);
            }
            if(stR <= edR){
                stC++;
            }
            else{
                break;
            }
        }
        return ans;
    }
};
// Problem_54(Spiral-Matrix)
// PROBLEM:- https://leetcode.com/problems/spiral-matrix/description
