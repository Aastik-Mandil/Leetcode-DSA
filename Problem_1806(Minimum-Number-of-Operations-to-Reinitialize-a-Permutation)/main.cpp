class Solution {
public:
    int reinitializePermutation(int n) {
        int count = 0;
        int i = 1;
        do{
            count++;
            if(i < (n/2)){
                i = 2*i;
            }
            else{
                i = (2*i) - n + 1;
            }
        }while(i != 1);

        return count;
    }
};
// i<(n/2) -> 2*i
// else -> 2*i - n + 1

// PROBLEM:- https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/description/
