class Solution {
    vector<string> makeStr(vector<string>& words, vector<int>& groups, int st){
        vector<string> ans;
        int idx = 0;
        while(idx < words.size()){
            if(groups[idx] != st){
                idx++;
                continue;
            }
            ans.push_back(words[idx++]);
            st ^= 1;
        }
        return ans;
    }
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<vector<string>> v(2);
        for(int i=0; i<words.size(); i++){
            v[groups[i]].push_back(words[i]);
        }

        vector<string> ans1 = makeStr(words, groups, 0);
        vector<string> ans2 = makeStr(words, groups, 1);
        if(ans1.size() >= ans2.size()){
            return ans1;
        }
        return ans2;
    }
};
// PROBLEM:- https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/description/
