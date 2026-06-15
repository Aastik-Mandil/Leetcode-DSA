class Solution {
    bool isPrime(int n){
        if(n == 1){
            return false;
        }
        for(int i=2; i<=sqrt(n); i++){
            if(n%i == 0){
                return false;
            }
        }
        return true;
    }
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        vector<int> v(101, 0);
        for(int &num: nums){
            v[num]++;
        }
        for(int i=0; i<=100; i++){
            if(v[i] > 0 && isPrime(v[i])){
                return true;
            }
        }
        return false;
    }
};
// PROBLEM:- https://leetcode.com/problems/check-if-any-element-has-prime-frequency/description/
