class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }

        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;
        for(int i=0;i<s.size();i++){
            char ch1 = s[i];
            char ch2 = t[i];
            if(mp1[ch1] == '\0' && mp2[ch2] == '\0'){
                mp1[ch1] = ch2;
                mp2[ch2] = ch1;
            }
            else if(mp1[ch1] == ch2 && mp2[ch2] == ch1){}
            else{
                return false;
            }
        }
        return true;
    }
};
// PROBLEM:- https://leetcode.com/problems/isomorphic-strings/description
