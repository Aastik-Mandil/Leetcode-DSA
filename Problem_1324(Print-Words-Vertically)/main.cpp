class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> ans;
        string z = "";
        int idx = 0, count = 0;
        for(char &ch: s){
            if(ch == ' '){
                count++;
                idx = 0;
            }
            else{
                if(ans.size()>idx){
                    while(ans[idx].size()<count){
                        ans[idx].push_back(' ');
                    }
                    ans[idx].push_back(ch);
                    if(z.size() < ans[idx].size()-1){
                        z+=" ";
                    }
                    idx++;
                }
                else{
                    ans.push_back(z+ch);
                    if(z.size() < ans.back().size()-1){
                        z+=" ";
                    }
                    idx++;
                }
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/print-words-vertically/description/
