long long int mod = 1e9 + 7;

class Solution {
public:
    long long int numR(string &s, string &t, int idx1,int idx2){
        if(idx2==0){
            return 1;
        }
        if(idx1==0){
            return 0;
        }
        if(s[idx1-1] == t[idx2-1]){
            return (numR(s,t,idx1-1,idx2-1)%mod + numR(s,t,idx1-1,idx2)%mod)%mod;
        }
        return numR(s,t,idx1-1,idx2)%mod;
    }
    long long int numM(string &s, string &t, int idx1,int idx2, vector<vector<long long int>> &dp){
        if(idx2==0){
            return dp[idx1][idx2] = 1;
        }
        if(idx1==0){
            return dp[idx1][idx2] = 0;
        }
        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2]%mod;
        }
        if(s[idx1-1] == t[idx2-1]){
            return dp[idx1][idx2] = (numM(s,t,idx1-1,idx2-1,dp)%mod + numM(s,t,idx1-1,idx2,dp)%mod)%mod;
        }
        return dp[idx1][idx2] = numM(s,t,idx1-1,idx2,dp)%mod;
    }
    long long int numT(string &s, string &t){
        vector<vector<long long int>> dp(s.size()+1, vector<long long int>(t.size()+1, 0));
        for(int idx1=0;idx1<=s.size();idx1++){
            dp[idx1][0] = 1;
        }
        for(int idx1=1;idx1<=s.size();idx1++){
            for(int idx2=1;idx2<=t.size();idx2++){
                if(s[idx1-1] == t[idx2-1]){
                    dp[idx1][idx2] = dp[idx1-1][idx2-1] + dp[idx1-1][idx2];
                }
                else{
                    dp[idx1][idx2] = dp[idx1-1][idx2];
                }
                dp[idx1][idx2] %= mod;
            }
        }
        return dp[s.size()][t.size()]%mod;
    }
    long long int numO(string &s, string &t){
        vector<long long int> dp(t.size()+1, 0);
        vector<long long int> curr(t.size()+1, 0);
        dp[0] = 1;
        curr[0] = 1;
        for(int idx1=1;idx1<=s.size();idx1++){
            for(int idx2=1;idx2<=t.size();idx2++){
                if(s[idx1-1] == t[idx2-1]){
                    curr[idx2] = dp[idx2-1] + dp[idx2];
                }
                else{
                    curr[idx2] = dp[idx2];
                }
                curr[idx2] %= mod;
            }
            dp = curr;
        }
        return dp[t.size()]%mod;
    }
    int numDistinct(string s, string t) {
        if(t.size() > s.size()){
            return 0;
        }
        if(s==t){
            return 1;
        }

        // return numR(s,t,s.size(),t.size());

        // vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, -1));
        // return numM(s,t,s.size(),t.size(),dp);

        // return numT(s,t);

        return numO(s,t);
    }
};
// PROBLEM:- https://leetcode.com/problems/distinct-subsequences/
