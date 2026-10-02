class Solution {
    int solveR(string &s1, string &s2, string &s3, int idx1, int idx2, int idx3){
        if(idx3 == 0){
            return idx1 == 0 && idx2 == 0;
        }
        if(idx1 == 0 && idx2 == 0){
            return 0;
        }
        if(idx1 > 0 && idx2 > 0 && s2[idx2-1] == s3[idx3-1] && s1[idx1-1] == s3[idx3-1]){
            return solveR(s1, s2, s3, idx1, idx2-1, idx3-1) || solveR(s1, s2, s3, idx1-1, idx2, idx3-1);
        }
        if(idx2 > 0 && s2[idx2-1] == s3[idx3-1]){
            return solveR(s1, s2, s3, idx1, idx2-1, idx3-1);
        }
        if(idx1 > 0 && s1[idx1-1] == s3[idx3-1]){
            return solveR(s1, s2, s3, idx1-1, idx2, idx3-1);
        }
        return 0;
    }
    int solveM(string &s1, string &s2, string &s3, int idx1, int idx2, int idx3, vector<vector<vector<int>>> &dp){
        if(idx3 == 0){
            return idx1 == 0 && idx2 == 0;
        }
        if(dp[idx3][idx1][idx2] != -1){
            return dp[idx3][idx1][idx2];
        }
        if(idx1 > 0 && idx2 > 0 && s2[idx2-1] == s3[idx3-1] && s1[idx1-1] == s3[idx3-1]){
            return dp[idx3][idx1][idx2] = solveM(s1, s2, s3, idx1, idx2-1, idx3-1, dp) || solveM(s1, s2, s3, idx1-1, idx2, idx3-1, dp);
        }
        if(idx2 > 0 && s2[idx2-1] == s3[idx3-1]){
            return dp[idx3][idx1][idx2] = solveM(s1, s2, s3, idx1, idx2-1, idx3-1, dp);
        }
        if(idx1 > 0 && s1[idx1-1] == s3[idx3-1]){
            return dp[idx3][idx1][idx2] = solveM(s1, s2, s3, idx1-1, idx2, idx3-1, dp);
        }
        return dp[idx3][idx1][idx2] = 0;
    }
    int solveT(string &s1, string &s2, string &s3){
        vector<vector<vector<int>>> dp(s3.size()+1, vector<vector<int>>(s1.size()+1, vector<int>(s2.size()+1, 0)));
        dp[0][0][0] = 1;
        for(int idx3=1; idx3<=s3.size(); idx3++){
            for(int idx1=0; idx1<=s1.size(); idx1++){
                for(int idx2=0; idx2<=s2.size(); idx2++){
                    if(idx1 > 0 && idx2 > 0 && s2[idx2-1] == s3[idx3-1] && s1[idx1-1] == s3[idx3-1]){
                        dp[idx3][idx1][idx2] = dp[idx3-1][idx1][idx2-1] || dp[idx3-1][idx1-1][idx2];
                    }
                    else if(idx2 > 0 && s2[idx2-1] == s3[idx3-1]){
                        dp[idx3][idx1][idx2] = dp[idx3-1][idx1][idx2-1];
                    }
                    else if(idx1 > 0 && s1[idx1-1] == s3[idx3-1]){
                        dp[idx3][idx1][idx2] = dp[idx3-1][idx1-1][idx2];
                    }
                    else{
                        dp[idx3][idx1][idx2] = 0;
                    }
                }
            }
        }
        return dp[s3.size()][s1.size()][s2.size()];
    }
    int solveO(string &s1, string &s2, string &s3){
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0)), curr(s1.size()+1, vector<int>(s2.size()+1, 0));
        dp[0][0] = curr[0][0] = 1;
        for(int idx3=1; idx3<=s3.size(); idx3++){
            for(int idx1=0; idx1<=s1.size(); idx1++){
                for(int idx2=0; idx2<=s2.size(); idx2++){
                    if(idx1 > 0 && idx2 > 0 && s2[idx2-1] == s3[idx3-1] && s1[idx1-1] == s3[idx3-1]){
                        curr[idx1][idx2] = dp[idx1][idx2-1] || dp[idx1-1][idx2];
                    }
                    else if(idx2 > 0 && s2[idx2-1] == s3[idx3-1]){
                        curr[idx1][idx2] = dp[idx1][idx2-1];
                    }
                    else if(idx1 > 0 && s1[idx1-1] == s3[idx3-1]){
                        curr[idx1][idx2] = dp[idx1-1][idx2];
                    }
                    else{
                        curr[idx1][idx2] = 0;
                    }
                }
            }
            dp = curr;;
        }
        return dp[s1.size()][s2.size()];
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()){
            return false;
        }

        // return solveR(s1, s2, s3, s1.size(), s2.size(), s3.size()) == 1;

        // vector<vector<vector<int>>> dp(s3.size()+1, vector<vector<int>>(s1.size()+1, vector<int>(s2.size()+1, -1)));
        // return solveM(s1, s2, s3, s1.size(), s2.size(), s3.size(), dp) == 1;

        // return solveT(s1, s2, s3) == 1;

        return solveO(s1, s2, s3) == 1;
    }
};
// PROBLEM:- https://leetcode.com/problems/interleaving-string/description
