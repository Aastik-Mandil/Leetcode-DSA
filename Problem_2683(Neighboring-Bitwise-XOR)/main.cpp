class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        vector<int> o1(n), o2(n);
        o1[0] = 0;
        o2[0] = 1;
        for(int i=0; i<(n-1); i++){
            o1[i+1] = derived[i] ^ o1[i];
            o2[i+1] = derived[i] ^ o2[i];
        }

        return derived[n-1] == (o1[n-1] ^ o1[0]) || derived[n-1] == (o2[n-1] ^ o2[0]);
    }
};
// PROBLEM:- https://leetcode.com/problems/neighboring-bitwise-xor/description/
