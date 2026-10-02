class Solution {
    int canTransformR(string s, unordered_map<string, bool> &mp, int idx, int k){
        if(mp[s]){
            return 1;
        }
        if(k == 0){
            return 0;
        }
        if(idx == s.size()){
            return 0;
        }
        if(canTransformR(s, mp, idx+1, k)){
            return 1;
        }
        char original = s[idx];
        for(char ch='a'; ch<='z'; ch++){
            s[idx] = ch;
            if(canTransformR(s, mp, idx+1, k-1)){
                return 1;
            }
        }
        s[idx] = original;
        return 0;
    }
    vector<string> solveB(vector<string>& queries, vector<string>& dictionary){
        unordered_map<string, bool> mp;
        for(string &s: dictionary){
            mp[s] = true;
        }

        vector<string> ans;
        for(int i=0; i<queries.size(); i++){
            string s = queries[i];
            bool flag = canTransformR(s, mp, 0, 2) == 1;
            if(flag){
                ans.push_back(s);
            }
        }
        return ans;
    }

    bool isDifference(string s, vector<string> &dictionary, int cnt){
        for(string &dict: dictionary){
            int diff = 0;
            for(int i=0; i<s.size(); i++){
                if(s[i] != dict[i]){
                    diff++;
                }
            }
            if(diff <= cnt){
                return true;
            }
        }
        return false;
    }
    vector<string> solveO(vector<string>& queries, vector<string>& dictionary){
        vector<string> ans;
        for(int i=0; i<queries.size(); i++){
            string s = queries[i];
            bool flag = isDifference(s, dictionary, 2);
            if(flag){
                ans.push_back(s);
            }
        }
        return ans;
    }
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        // return solveB(queries, dictionary);

        return solveO(queries, dictionary);
    }
};
// PROBLEM:- https://leetcode.com/problems/words-within-two-edits-of-dictionary/description/
