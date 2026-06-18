class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s == ""){
            return true;
        }
        int i=0;
        for(char &ch: t){
            if(ch == s[i]){
                i++;
            }
            if(i==s.size()){
                return true;
            }
        }
        return false;
    }
};
// PROBLEM:- https://leetcode.com/problems/is-subsequence/description/
