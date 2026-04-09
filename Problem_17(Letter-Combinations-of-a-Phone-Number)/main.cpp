class Solution {
    vector<string> ans;
    vector<string> t={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void solve(string &digits,int idx,string z){
        if(idx == digits.size()){
            ans.push_back(z);
            return;
        }
        string s = t[digits[idx]-'0'];
        for(int i=0;i<s.size();i++){
            z.push_back(s[i]);
            solve(digits,idx+1,z);
            z.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string z="";
        solve(digits,0,z);
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
