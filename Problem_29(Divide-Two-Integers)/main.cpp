class Solution {
public:
    int divide(int dividend, int divisor) {
        bool neg = false;
        if(dividend<0){
            neg = !neg;
        }
        if(divisor<0){
            neg = !neg;
        }

        long long que = dividend;
        que = abs(que);
        long long rem = divisor;
        rem = abs(rem);

        if(abs(rem) == 1){
            if(que > pow(2, 31) - 1){
                return neg ? -pow(2, 31) : pow(2, 31)-1;
            }
            if(que == pow(2, 31) - 1){
                return neg ? -(pow(2, 31)-1) : pow(2, 31)-1;
            }
            if(que < -pow(2, 31)){
                return neg ? -pow(2, 31) : pow(2, 31)-1;
            }
            if(que == -pow(2, 31)){
                return neg ? -pow(1, 31) : pow(2, 31)-1;
            }
        }

        int count = 0;
        if(que<rem){
            return 0;
        }
        while(que>=rem){
            que-=rem;
            count++;
        }
        return neg ? -count : count;
    }
};
// PROBLEM:- https://leetcode.com/problems/divide-two-integers/description/
