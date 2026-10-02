class Solution {
    int countSetBit(int n){
        if(n == 0){
            return 0;
        }
        return 1 + countSetBit(n & (n-1));
    }
public:
    int minOperations(vector<int>& nums, int k) {
        int val = k;
        for(int &num: nums){
            val ^= num;
        }
        return countSetBit(val);
    }
};
// PROBLEM:- https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/description/
