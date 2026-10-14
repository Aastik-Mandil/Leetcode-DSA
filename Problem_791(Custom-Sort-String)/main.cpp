class Solution {
public:
    string customSortString(string order, string s) {
        // calculate the count of char in s
        vector<int> v(26, 0);
        for(char &ch: s){
            v[ch-'a']++;
        }

        // create the new string based on the order
        string ans = "";
        for(char &ch: order){
            while(v[ch-'a'] > 0){
                ans.push_back(ch);
                v[ch-'a']--;
            }
        }

        // now use the character which is not in order (remaining)
        for(int i=0; i<26; i++){
            while(v[i] > 0){
                ans.push_back(i+'a');
                v[i]--;
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/custom-sort-string/description/
