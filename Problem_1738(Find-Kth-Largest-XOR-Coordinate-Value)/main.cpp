class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();

        // create range based xor for every row and col
        vector<int> v;
        v.push_back(matrix[0][0]);
        for(int j=1; j<m; j++){
            matrix[0][j] ^= matrix[0][j-1];
            v.push_back(matrix[0][j]);
        }
        for(int i=1; i<n; i++){
            matrix[i][0] ^= matrix[i-1][0];
            v.push_back(matrix[i][0]);
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                int val = matrix[i-1][j];
                val ^= matrix[i][j-1];
                val ^= matrix[i-1][j-1];
                matrix[i][j] ^= val;
                v.push_back(matrix[i][j]);
            }
        }

        // sort in descending order
        sort(v.begin(), v.end(), greater<int>());

        return v[k-1];
    }
};
// PROBLEM:- https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/
