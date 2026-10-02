class Solution {
    string getString(string &word){
        vector<int> v(26, 0);
        for(char &ch: word){
            v[ch-'a']++;
        }
        string ans = "";
        for(int i=0; i<26; i++){
            ans.push_back('a'+i);
            ans += to_string(v[i]);
        }
        return ans;
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {
        unordered_map<string, string> mp;
        vector<string> ans;
        for(int i=0; i<words.size(); i++){
            string word = words[i];
            string key = getString(word);
            if(ans.size() == 0 || mp[ans.back()] != key){
                ans.push_back(word);
            }
            mp[word] = key;
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/description/
