class Solution {
public:
    string stringHash(string s, int k) {
        string ans = "";
        for(int i=0; i<s.size(); i+=k){
            int total = 0;
            for(int j=i; j<(i+k); j++){
                total += (s[j]-'a');
            }
            int rem = total%26;
            ans.push_back(rem+'a');
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/hash-divided-string/description/
