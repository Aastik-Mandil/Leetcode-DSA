class Solution {
public:
    int mySqrt(int x) {
        if(x == 0){
            return 0;
        }
        long long res = x;
        long long l = 1, r = res;
        int ans = -1;
        while(l<=r){
            long long mid = l+((r-l)/2);
            if((mid*mid) == res){
                return mid;
            }
            if((mid*mid) > res){
                r = mid-1;
            }
            else{
                ans = mid;
                l = mid+1;
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/sqrtx/description
