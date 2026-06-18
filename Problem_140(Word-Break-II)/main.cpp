class Solution {
    vector<string> ans;
    void solve(string &s, vector<string> &wordDict, string t, string z, int idx){
        if(idx == s.size()){
            if(find(wordDict.begin(), wordDict.end(), z) != wordDict.end()){
                t+=" "+z;
                ans.push_back(t);
            }
            return;
        }
        z.push_back(s[idx]);
        if(find(wordDict.begin(), wordDict.end(), z) != wordDict.end()){
            solve(s, wordDict, t+" "+z, "", idx+1);
        }
        solve(s, wordDict, t, z, idx+1);
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        ans.clear();
        string t = "";
        string z = "";
        solve(s, wordDict, t, z, 0);

        for(int i=0; i<ans.size(); i++){
            ans[i] = ans[i].substr(1);
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/word-break-ii/description/
