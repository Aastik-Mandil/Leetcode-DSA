class Solution {
    vector<int> getCount(int n){
        vector<int> z(3, 0);
        while(n>1){
            if(n%10 == 0){
                z[0]++;
                n/=10;
            }
            else if(n%5 == 0){
                z[1]++;
                n/=5;
            }
            else if(n%2 == 0){
                z[2]++;
                n/=2;
            }
            else{
                break;
            }
        }
        return z;
    }
public:
    int trailingZeroes(int n) {
        int st = 1;
        int res2 = 0;
        int res5 = 0;
        int res10 = 0;
        vector<int> ans(3, 0);
        while(st<=n){
            vector<int> t = getCount(st);
            ans[0] += t[0];
            ans[1] += t[1];
            ans[2] += t[2];
            st+=1;
        }
        return ans[0] + min(ans[1], ans[2]);
    }
};
// PROBLEM:- https://leetcode.com/problems/factorial-trailing-zeroes/description
