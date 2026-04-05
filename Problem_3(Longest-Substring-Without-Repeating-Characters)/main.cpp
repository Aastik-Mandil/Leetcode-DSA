class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int l=0,r=0,ans=0;
        while(r<s.size()){
            if(mp[s[r]]>0){
                ans=max(ans,r-l);
                while(l<r && mp[s[r]]>0){
                    mp[s[l]]=0;
                    l++;
                }
            }
            mp[s[r]]=r+1;
            r++;
        }
        return max(ans,r-l);
    }
};
// PROBLEM:- https://leetcode.com/problems/longest-substring-without-repeating-characters/
