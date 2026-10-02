class Solution {
public:
    int maxDistinct(string s) {
        vector<int> v(26, 0);
        for(int i=0; i<s.size(); i++){
            v[s[i]-'a'] = 1;
        }
        int count = 0;
        for(int i=0; i<26; i++){
            if(v[i] > 0){
                count++;
            }
        }
        return count;
    }
};
// PROBLEM:- https://leetcode.com/problems/maximum-substrings-with-distinct-start/description/
