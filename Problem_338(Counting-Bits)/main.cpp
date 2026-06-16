class Solution {
    int getBits(int n){
        if(n <= 1){
            return n;
        }
        return 1 + getBits(n & (n-1));
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0; i<=n; i++){
            ans.push_back(getBits(i));
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/counting-bits/description
