class Solution {
    vector<string> v;
    void solve(int n, string z, int k){
        if(v.size() > k){
            return;
        }
        if(z.size() == n){
            v.push_back(z);
            return;
        }
        for(char ch='a'; ch<='c'; ch++){
            if(z.size() == 0 || z[z.size()-1] != ch){
                z.push_back(ch);
                solve(n, z, k);
                z.pop_back();
            }
        }
    }
public:
    string getHappyString(int n, int k) {
        v.clear();
        string z = "";
        solve(n, z, k);
        if(k>v.size()){
            return "";
        }
        return v[k-1];
    }
};
// PROBLEM:- https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/
