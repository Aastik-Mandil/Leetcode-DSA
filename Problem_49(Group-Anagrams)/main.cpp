class Solution {
    string getKey(string &s){
        vector<int> v(26,0);
        for(char &ch: s){
            v[ch-'a']++;
        }
        string k = "";
        for(int i=0;i<26;i++){
            k.push_back(i+'a');
            k.push_back(':');
            k.push_back(v[i]);
            k.push_back(',');
        }
        return k;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string &s: strs){
            mp[getKey(s)].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            ans.push_back(itr->second);
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/group-anagrams/description/
