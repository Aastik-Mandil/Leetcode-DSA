class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }

        vector<string> v(numRows, "");
        int i=0;
        bool asc = true;
        for(char &ch: s){
            v[i].push_back(ch);
            if(i==0){
                asc = true;
            }
            else if(i == numRows-1){
                asc = false;
            }
            if(asc){
                i++;
            }
            else{
                i--;
            }
        }
        string ans="";
        for(string &s: v){
            ans+=s;
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/zigzag-conversion/description/
