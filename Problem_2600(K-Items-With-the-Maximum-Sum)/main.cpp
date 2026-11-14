class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if(k <= numOnes){
            return k;
        }
        if(k <= (numOnes + numZeros)){
            return numOnes;
        }
        if(k <= (numOnes + numZeros + numNegOnes)){
            return numOnes - (k-numOnes-numZeros);
        }
        return numOnes - numZeros;
    }
};
// PROBLEM:- https://leetcode.com/problems/k-items-with-the-maximum-sum/description/
