class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> v(26, 0);
        for(char &ch: s){
            v[ch-'a']++;
        }
        for(char &ch: t){
            v[ch-'a']--;
        }
        int ans = 0;
        for(int i=0; i<26; i++){
            if(v[i] < 0){
                ans += abs(v[i]);
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/
