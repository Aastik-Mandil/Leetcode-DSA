class Solution {
    unordered_map<int, int> mp;
    int getNextNumber(int n){
        int total = 0;
        while(n>0){
            total+=pow(n%10,2);
            n/=10;
        }
        return total;
    }
public:
    bool isHappy(int n) {
        if(n == 1){
            return true;
        }
        if(mp[n]>0){
            return false;
        }
        mp[n] = 1;
        int num = getNextNumber(n);
        return isHappy(num);
    }
};
// PROBLEM:- https://leetcode.com/problems/happy-number/description
