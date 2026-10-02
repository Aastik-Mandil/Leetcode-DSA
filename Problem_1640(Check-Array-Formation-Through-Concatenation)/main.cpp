class Solution {
    bool canPick(vector<int> &arr, vector<vector<int>> &pieces, int idx1, int idx2){
        int n = pieces[idx2].size();
        int j = idx1;
        for(int i=0; i<n; i++){
            if(j >= arr.size()){
                return false;
            }
            if(arr[j] != pieces[idx2][i]){
                return false;
            }
            j++;
        }
        return true;
    }

    int solveR(vector<int> &arr, vector<vector<int>> &pieces, vector<bool> &visited, int idx1, int idx2){
        if(idx1 == arr.size()){
            return 1;
        }
        if(idx2 == pieces.size()){
            return 0;
        }
        if(visited[idx2]){
            return solveR(arr, pieces, visited, idx1, idx2+1);
        }
        if(canPick(arr, pieces, idx1, idx2)){
            visited[idx2] = true;
            if(solveR(arr, pieces, visited, idx1+pieces[idx2].size(), 0) == 1){
                return 1;
            }
            visited[idx2] = false;
        }
        return solveR(arr, pieces, visited, idx1, idx2+1);
    }
    int solveM(vector<int> &arr, vector<vector<int>> &pieces, vector<bool> &visited, vector<vector<int>> &dp, int idx1, int idx2){
        if(idx1 == arr.size()){
            return dp[idx1][idx2] = 1;
        }
        if(idx2 == pieces.size()){
            return dp[idx1][idx2] = 0;
        }
        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }
        if(visited[idx2]){
            return dp[idx1][idx2] = solveM(arr, pieces, visited, dp, idx1, idx2+1);
        }
        if(canPick(arr, pieces, idx1, idx2)){
            visited[idx2] = true;
            if(solveM(arr, pieces, visited, dp, idx1+pieces[idx2].size(), 0) == 1){
                return dp[idx1][idx2] = 1;
            }
            visited[idx2] = false;
        }
        return dp[idx1][idx2] = solveM(arr, pieces, visited, dp, idx1, idx2+1);
    }
    int solveT(vector<int> &arr, vector<vector<int>> &pieces, vector<bool> &visited, int n){
        vector<vector<int>> dp(arr.size()+1, vector<int>(n+1, -1));
        for(int idx2=0; idx2<=n; idx2++){
            dp[arr.size()][idx2] = 1;
        }
        for(int idx1=0; idx1<arr.size(); idx1++){
            dp[idx1][n] = 0;
        }
        for(int idx1=arr.size()-1; idx1>=0; idx1--){
            for(int idx2=n-1; idx2>=0; idx2--){
                if(visited[idx2]){
                    dp[idx1][idx2] = dp[idx1][idx2+1];
                }
                else{
                    if(canPick(arr, pieces, idx1, idx2)){
                        visited[idx2] = true;
                        if(dp[idx1+pieces[idx2].size()][0] == 1){
                            dp[idx1][idx2] = 1;
                        }
                        else{
                            visited[idx2] = false;
                        }
                    }
                    else{
                        dp[idx1][idx2] = solveM(arr, pieces, visited, dp, idx1, idx2+1);
                    }
                }
            }
        }
        return dp[0][0];
    }
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int n = pieces.size();
        vector<bool> visited(n, false);

        // return solveR(arr, pieces, visited, 0, 0) == 1;

        // vector<vector<int>> dp(arr.size()+1, vector<int>(n+1, -1));
        // return solveM(arr, pieces, visited, dp, 0, 0) == 1;

        return solveT(arr, pieces, visited, n) == 1;
    }
};
// PROBLEM:- https://leetcode.com/problems/check-array-formation-through-concatenation/description/
