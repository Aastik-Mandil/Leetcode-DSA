class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        while(n != 0){
            int val = log2(n);
            int num = pow(2, val);
            int num1 = pow(2, val+1);
            if(abs(n-num) < abs(n-num1)){
                n -= num;
            }
            else{
                n -= num1;
            }
            ans++;
            n = abs(n);
            if(n == 0){
                return ans;
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/description/
