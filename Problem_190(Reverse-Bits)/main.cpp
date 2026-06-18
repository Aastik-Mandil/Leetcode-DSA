class Solution {
public:
    int reverseBits(int n) {
        string s = "";
        for(int i=0; i<32; i++){
            int val = n>>i;
            s += to_string(val&1);
        }

        int ans=0;
        for(int i=0; i<32; i++){
            ans = ans<<1;
            if(s[i] == '1'){
                ans |= 1;
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/reverse-bits/description
