class Solution {
    bool isPalindrome(string &s, int st, int ed){
        if(st<0){
            st = 0;
        }
        // cout<<st<<" "<<ed<<endl;
        int i=st, j=ed-1;
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int cutR(string &s, int idx, int last){
        if(idx==0){
            if(isPalindrome(s, idx-1, last)){
                return 0;
            }
            return INT_MAX;
        }
        if(!isPalindrome(s, idx-1, last)){
            return cutR(s, idx-1, last);
        }
        return min(
            1+cutR(s, idx-1, idx-1),
            cutR(s, idx-1, last)
        );
    }
    int cutM(string &s, int idx, int last, vector<vector<int>> &dp){
        if(idx==0){
            if(isPalindrome(s, idx-1, last)){
                return dp[idx][last] = 0;
            }
            return dp[idx][last] = INT_MAX;
        }
        if(dp[idx][last] != -1){
            return dp[idx][last];
        }
        if(!isPalindrome(s, idx-1, last)){
            return dp[idx][last] = cutM(s, idx-1, last, dp);
        }
        return dp[idx][last] = min(
            1+cutM(s, idx-1, idx-1, dp),
            cutM(s, idx-1, last, dp)
        );
    }
    int cutT(string &s){
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, INT_MAX));
        for(int last=0;last<=s.size();last++){
            if(isPalindrome(s, 0, last)){
                dp[0][last] = 0;
            }
        }
        for(int idx=1;idx<=s.size();idx++){
            for(int last=0;last<=s.size();last++){
                if(isPalindrome(s, idx-1, last)){
                    dp[idx][last] = min(
                        1+dp[idx-1][idx-1],
                        dp[idx-1][last]
                    );
                }
                else{
                    dp[idx][last] = dp[idx-1][last];
                }
            }
        }
        return dp[s.size()][s.size()];
    }
    int cutO(string &s){
        vector<int> dp(s.size()+1, INT_MAX), curr(s.size()+1, INT_MAX);
        for(int last=0;last<=s.size();last++){
            if(isPalindrome(s, 0, last)){
                dp[last] = 0;
            }
        }
        for(int idx=1;idx<=s.size();idx++){
            for(int last=0;last<=s.size();last++){
                if(isPalindrome(s, idx-1, last)){
                    curr[last] = min(
                        1+dp[idx-1],
                        dp[last]
                    );
                }
                else{
                    curr[last] = dp[last];
                }
            }
            dp = curr;
        }
        return dp[s.size()];
    }
public:
    int minCut(string s) {
        // return cutR(s, s.size(), s.size());

        // vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, -1));
        // return cutM(s, s.size(), s.size(), dp);

        // return cutT(s);

        return cutO(s);
    }
};
// PROBLEM:- https://leetcode.com/problems/palindrome-partitioning-ii/description/
