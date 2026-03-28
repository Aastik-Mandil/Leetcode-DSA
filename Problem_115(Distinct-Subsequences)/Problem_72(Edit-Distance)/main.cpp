long long int mod = 1e9 + 7;

class Solution {
public:
    int distanceR(string &s, string &t,int idx1, int idx2){
        if(idx1 == 0 || idx2 == 0){
            return max(idx1, idx2);
        }
        if(s[idx1-1] == t[idx2-1]){
            return distanceR(s, t, idx1-1, idx2-1);
        }
        return 1 + min(
            distanceR(s, t, idx1-1, idx2),
            min(
                distanceR(s, t, idx1, idx2-1),
                distanceR(s, t, idx1-1, idx2-1)
            )
        );
    }
    int distanceM(string &s, string &t,int idx1, int idx2, vector<vector<int>> &dp){
        if(idx1 == 0 || idx2 == 0){
            return dp[idx1][idx2] = max(idx1, idx2);
        }
        if(dp[idx1][idx2] != INT_MAX){
            return dp[idx1][idx2];
        }
        if(s[idx1-1] == t[idx2-1]){
            return dp[idx1][idx2] = distanceM(s, t, idx1-1, idx2-1, dp);
        }
        return dp[idx1][idx2] = 1 + min(
            distanceM(s, t, idx1-1, idx2, dp),
            min(
                distanceM(s, t, idx1, idx2-1, dp),
                distanceM(s, t, idx1-1, idx2-1, dp)
            )
        );
    }
    int distanceT(string &s, string &t){
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
        for(int idx1=0;idx1<=s.size();idx1++){
            dp[idx1][0]=max(idx1,0);
        }
        for(int idx2=0;idx2<=t.size();idx2++){
            dp[0][idx2]=max(idx2,0);
        }
        for(int idx1=1;idx1<=s.size();idx1++){
            for(int idx2=1;idx2<=t.size();idx2++){
                if(s[idx1-1] == t[idx2-1]){
                    dp[idx1][idx2] = dp[idx1-1][idx2-1];
                }
                else{
                    dp[idx1][idx2] = 1 + min(dp[idx1-1][idx2], min(dp[idx1][idx2-1], dp[idx1-1][idx2-1]));
                }
                dp[idx1][idx2] %= mod;
            }
        }
        return dp[s.size()][t.size()]%mod;
    }
    int distanceO(string &s, string &t){
        vector<int> dp(t.size()+1, 0),curr(t.size()+1, 0);
        for(int idx2=0;idx2<=t.size();idx2++){
            dp[idx2] = curr[idx2] = idx2;
        }
        for(int idx1=1;idx1<=s.size();idx1++){
            curr[0] = idx1;
            for(int idx2=1;idx2<=t.size();idx2++){
                if(s[idx1-1] == t[idx2-1]){
                    curr[idx2] = dp[idx2-1];
                }
                else{
                    curr[idx2] = 1 + min(dp[idx2], min(curr[idx2-1], dp[idx2-1]));
                }
                curr[idx2] %= mod;
            }
            dp = curr;
        }
        for(int idx2=0;idx2<=t.size();idx2++){
            cout<<dp[idx2]<<" ";
        }
        cout<<endl;
        return dp[t.size()]%mod;
    }
    int minDistance(string word1, string word2) {
        // return distanceR(word1, word2, word1.size(), word2.size());

        // vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, INT_MAX));
        // return distanceM(word1, word2, word1.size(), word2.size(), dp);

        // return distanceT(word1, word2);

        return distanceO(word1, word2);
    }
};
// PROBLEM:- https://leetcode.com/problems/edit-distance/description/
