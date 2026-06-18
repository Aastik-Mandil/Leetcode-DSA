class Solution {
    int ans=0;
    void solve(string &s, int idx, vector<string> v, string z){
        if(idx == s.size()){
            if(z.size()>0 && find(v.begin(), v.end(), z) == v.end()){
                v.push_back(z);
            }
            if(ans < v.size()){
                ans = v.size();
            }
            return;
        }
        for(int i=idx;i<s.size();i++){
            z.push_back(s[i]);
            if(find(v.begin(), v.end(), z) == v.end()){
                v.push_back(z);
                solve(s, i+1, v, "");
                v.pop_back();
            }
        }
    }
public:
    int maxUniqueSplit(string s) {
        ans=0;
        vector<string> v;
        string z="";
        solve(s,0,v,z);
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/
