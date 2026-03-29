class Solution {
public:
    vector<vector<int>> lcsT(string &s1, string &s2){
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
        return dp;
    }
    string shortestCommonSupersequence(string text1, string text2) {
        vector<vector<int>> dp = lcsT(text1, text2);

        string ans="";
        int i=text1.size(),j=text2.size();
        while(i>0 && j>0){
            if(text1[i-1] == text2[j-1]){
                ans = text1[i-1] + ans;
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                ans = text1[i-1] + ans;
                i--;
            }
            else{
                ans = text2[j-1] + ans;
                j--;
            }
        }
        while(i>0){
            ans = text1[i-1] + ans;
            i--;
        }
        while(j>0){
            ans = text2[j-1] + ans;
            j--;
        }

        return ans;
    }
};
