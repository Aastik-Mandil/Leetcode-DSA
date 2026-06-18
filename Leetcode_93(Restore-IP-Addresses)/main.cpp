class Solution {
    vector<string> ans;
    bool isValid(string z){
        int count = 0;
        string t = "";
        int zero = 0;
        for(int idx = z.size()-1; idx>=0 && z[idx]!='.'; idx--){
            count++;
            t = z[idx]+t;
            if(z[idx] == '0'){
                zero++;
            }
        }
        if(count == 0 || t.size() > 3){
            return false;
        }
        if(t == "0"){
            return true;
        }
        if(t.size()>1 && t[0] == '0'){
            return false;
        }
        if(stoi(t) <= 255){
            return true;
        }
        return false;
    }
    void solve(string &s, int idx, string z, int count){
        if(idx == s.size()){
            if(count == 0 && isValid(z)){
                ans.push_back(z);
            }
            return;
        }
        if(count == 0){
            solve(s, idx+1, z+s[idx], count);
            return;
        }
        if(isValid(z)){
            solve(s, idx+1, z+'.'+s[idx], count-1);
        }
        solve(s, idx+1, z+s[idx], count);
    }
public:
    vector<string> restoreIpAddresses(string s) {
        ans.clear();
        if(s.size()>12 || s.size()<4){
            return ans;
        }
        string z = "";
        char ch = '\0';
        solve(s, 0, z, 3);
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/restore-ip-addresses/description/
