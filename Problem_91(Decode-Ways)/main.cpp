class Solution {
    int solveR(string &s, int idx){
        if(idx == s.size()){
            return 1;
        }
        int total = 0;
        // 1 step
        if(s[idx] != '0'){
            total += solveR(s, idx+1);
        }
        else{
            return 0;
        }
        // 2 step
        if(idx+1 < s.size()){
            if(stoi(s.substr(idx,2)) <= 26){
                total += solveR(s, idx+2);
            }
        }
        return total;
    }
    int solveM(string &s, int idx, vector<int> &dp){
        if(idx == s.size()){
            return 1;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int total = 0;
        // 1 step
        if(s[idx] != '0'){
            total += solveM(s, idx+1, dp);
        }
        else{
            return 0;
        }
        // 2 step
        if(idx+1 < s.size()){
            if(stoi(s.substr(idx,2)) <= 26){
                total += solveM(s, idx+2, dp);
            }
        }
        return dp[idx] = total;
    }
    int solveT(string &s){
        vector<int> dp(s.size()+1, 0);
        dp[s.size()] = 1;
        for(int idx=s.size()-1;idx>=0;idx--){
            int total = 0;
            // 1 step
            if(s[idx] == '0'){
                dp[idx] = 0;
            }
            else{
                total += dp[idx+1];
                // 2 step
                if(idx+1 < s.size()){
                    if(stoi(s.substr(idx,2)) <= 26){
                        total += dp[idx+2];
                    }
                }
                dp[idx] = total;
            }
        }
        return dp[0];
    }
public:
    int numDecodings(string s) {
        // return solveR(s, 0);

        // vector<int> dp(s.size()+1, -1);
        // return solveM(s, 0, dp);

        return solveT(s);
    }
};
// PROBLEM:- https://leetcode.com/problems/decode-ways/description/
