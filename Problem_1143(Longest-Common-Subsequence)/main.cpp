class Solution {
public:
    int lcsR(string &s1, string &s2, int idx1, int idx2){
        if(idx1==0 || idx2==0){
            return 0;
        }
        if(s1[idx1-1] ==s2[idx2-1]){
            return 1 + lcsR(s1, s2, idx1-1, idx2-1);
        }
        return max(
            lcsR(s1, s2, idx1, idx2-1),
            lcsR(s1, s2, idx1-1, idx2)
        );
    }
    int lcsM(string &s1, string &s2, int idx1, int idx2, vector<vector<int>> &dp){
        if(idx1==0 || idx2==0){
            return dp[idx1][idx2] = 0;
        }
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }
        if(s1[idx1-1] == s2[idx2-1]){
            return dp[idx1][idx2] = 1 + lcsM(s1, s2, idx1-1, idx2-1, dp);
        }
        return dp[idx1][idx2] = max(
            lcsM(s1, s2, idx1, idx2-1, dp),
            lcsM(s1, s2, idx1-1, idx2, dp)
        );
    }
    int lcsT(string &s1, string &s2){
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        for(int idx1=1;idx1<=s1.size();idx1++){
            for(int idx2=1;idx2<=s2.size();idx2++){
                if(s1[idx1-1] == s2[idx2-1]){
                    dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
                }
                else{
                    dp[idx1][idx2] = max(dp[idx1][idx2-1], dp[idx1-1][idx2]);
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
    int lcsO(string &s1, string &s2){
        vector<int> dp(s2.size()+1, 0),curr(s2.size()+1, 0);
        for(int idx1=1;idx1<=s1.size();idx1++){
            for(int idx2=1;idx2<=s2.size();idx2++){
                if(s1[idx1-1] == s2[idx2-1]){
                    curr[idx2] = 1 + dp[idx2-1];
                }
                else{
                   curr[idx2] = max(curr[idx2-1], dp[idx2]);
                }
            }
            dp = curr;
        }
        return dp[s2.size()];
    }
    int longestCommonSubsequence(string text1, string text2) {
        // return lcsR(text1, text2, text1.size(), text2.size());

        // vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, -1));
        // return lcsM(text1, text2, text1.size(), text2.size(), dp);

        // return lcsT(text1, text2);

        return lcsO(text1, text2);
    }
};
// PROBLEM:- https://leetcode.com/problems/longest-common-subsequence/
