class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string z = "";
        int idx = 0;
        unordered_map<char, string> c2w;
        unordered_map<string, char> w2c;
        for(char &ch: s){
            if(ch == ' '){
                if(idx >= pattern.size()){
                    return false;
                }
                char t = pattern[idx++];
                if(c2w[t] == "" && w2c[z] == '\0'){
                    c2w[t] = z;
                    w2c[z] = t;
                }
                else if(c2w[t] == z && w2c[z] == t){}
                else{
                    return false;
                }
                z="";
            }
            else{
                z.push_back(ch);
            }
        }
        char t = pattern[idx++];
        if(c2w[t] == "" && w2c[z] == '\0'){
            c2w[t] = z;
            w2c[z] = t;
        }
        else if(c2w[t] == z && w2c[z] == t){}
        else{
            return false;
        }
        return idx == pattern.size();
    }
};
// PROBLEM:- https://leetcode.com/problems/word-pattern/description
