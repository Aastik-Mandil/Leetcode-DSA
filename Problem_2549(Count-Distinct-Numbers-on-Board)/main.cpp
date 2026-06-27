class Solution {
public:
    int distinctIntegers(int n) {
        if(n == 1){
            return 1;
        }
        return n-1;
    }
};
// PROBLEM:- https://leetcode.com/problems/count-distinct-numbers-on-board/description/
