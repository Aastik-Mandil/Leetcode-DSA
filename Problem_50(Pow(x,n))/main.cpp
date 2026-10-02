class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0.00000){
            return x;
        }
        if(n == 0){
            return 1.00000;
        }
        if(x == 1.00000 || x == -1.00000){
            return n%2 == 0 ? abs(x) : x;
        }

        double val = 1.00000;
        long long i=0;
        if(n<0){
            while(i>n){
                val/=x;
                i--;
                if(val==0.00000){
                    return 0.00000;
                }
            }
        }
        else{
            while(i<n){
                val*=x;
                i++;
            }
        }
        return val;
    }
};
// PROBLEM:- https://leetcode.com/problems/powx-n/description/
