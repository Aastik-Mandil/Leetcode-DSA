class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n%2 == 0 && m%2 == 0){
            return 0;
        }
        int ans = 0;
        if(n%2 == 0 && m%2 != 0){
            for(int &num: nums1){
                ans ^= num;
            }
        }
        else if(n%2 != 0 && m%2 == 0){
            for(int &num: nums2){
                ans ^= num;
            }
        }
        else{
            for(int &num: nums1){
                ans ^= num;
            }
            for(int &num: nums2){
                ans ^= num;
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/bitwise-xor-of-all-pairings/description/

// Cases:-
// n%2 == 0 && m%2 == 0 -> 0
// n%2 == 0 && m%2 != 0 -> xor of even length array
// n%2 != 0 && m%2 == 0 -> xor of even length array
// n%2 != 0 && m%2 != 0 -> xor of both arrays
