class Solution {
    int solveR(vector<int> &arr, int start, vector<int> &visited){
        if(arr[start] == 0) {
            return 1;
        }
        if(find(visited.begin(), visited.end(), start) != visited.end()){
            return 0;
        }
        visited.push_back(start);
        int left = 0;
        if(start - arr[start] >= 0){
            left = solveR(arr, start-arr[start], visited);
        }
        int right = 0;
        if(start + arr[start] < arr.size()){
            right = solveR(arr, start+arr[start], visited);
        }
        return left | right;
    }
    int solveM(vector<int> &arr, int start, vector<int> &visited, vector<int> &dp){
        if(arr[start] == 0) {
            return dp[start] = 1;
        }
        if(dp[start] != -1){
            return dp[start];
        }
        if(find(visited.begin(), visited.end(), start) != visited.end()){
            return dp[start] = 0;
        }
        visited.push_back(start);
        if(start - arr[start] >= 0){
            int left = solveM(arr, start-arr[start], visited, dp);
            if(left == 1){
                return dp[start] = 1;
            }
        }
        if(start + arr[start] < arr.size()){
            int right = solveM(arr, start+arr[start], visited, dp);
            if(right == 1){
                return dp[start] = 1;
            }
        }
        return dp[start] = 0;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> visited;
        
        // return solveR(arr, start, visited) == 1;

        vector<int> dp(arr.size(), -1);
        return solveM(arr, start, visited, dp) == 1;
    }
};
// PROBLEM:- https://leetcode.com/problems/jump-game-iii/description/
