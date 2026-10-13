class Solution {
    string getGroupKey(string s){
        // get count based on even/odd index
        vector<int> even(26, 0), odd(26, 0);
        for(int i=0; i<s.size(); i++){
            if(i%2 == 0){
                even[s[i]-'a']++;
            }
            else{
                odd[s[i]-'a']++;
            }
        }

        // concatenate both even and odd value and create key
        string z1 = "", z2 = "";
        for(int i=0; i<26; i++){
            z1.push_back('a'+i);
            z1 += to_string(even[i]);
            z2.push_back('a'+i);
            z2 += to_string(odd[i]);
        }
        return z1+"-"+z2;
    }
public:
    int numSpecialEquivGroups(vector<string>& words) {
        // group based on each work key
        unordered_map<string, int> mp;
        for(string &word: words){
            mp[getGroupKey(word)]++;
        }
        return mp.size();
    }
};
// PROBLEM:- https://leetcode.com/problems/groups-of-special-equivalent-strings/description/
