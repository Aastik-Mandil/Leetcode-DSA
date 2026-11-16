class Solution {
public:
    int longestStrChain(vector<string>& words) {
        // sort the list on the basis of size
        sort(words.begin(), words.end(), [](string &a, string &b){
            return a.size() < b.size();
        });

        // create a map which store all possible string it will make.
        // After removing each char and use it for chain
        unordered_map<string, int> mp; // {string: length}
        int ans = 0;
        for(string &word: words){
            for(int i=0; i<word.size(); i++){
                string s = word.substr(0, i) + word.substr(i+1, word.size());
                mp[word] = max(mp[word], mp[s] + 1);
                ans = max(ans, mp[word]);
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/longest-string-chain/description/
