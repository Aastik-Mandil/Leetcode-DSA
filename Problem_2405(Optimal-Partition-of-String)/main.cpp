class Solution {
    void reset(vector<int> &v){
        for(int i=0; i<26; i++){
            v[i] = 0;
        }
    }
public:
    int partitionString(string s) {
        vector<int> v(26, 0);
        int count = 1;
        for(char &ch: s){
            if(v[ch-'a'] > 0){
                count++;
                reset(v);
            }
            v[ch-'a']++;
        }
        return count;
    }
};
// PROBLEM:- https://leetcode.com/problems/optimal-partition-of-string/description/
