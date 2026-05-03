class Solution {
public:
    bool rotateString(string s, string goal) {
        string s1 = s+s;
        for(int i=0; i<s.size(); i++){
            if(s1.substr(i, s.size()) == goal){
                return true;
            }
        }
        return false;
    }
};
// PROBLEM:- https://leetcode.com/problems/rotate-string/description
