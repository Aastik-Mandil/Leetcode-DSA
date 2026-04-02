class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j=numbers.size()-1;
        while(i<j){
            int val = numbers[i]+numbers[j];
            if(val == target){
                return {i+1, j+1};
            }
            if(val > target){
                j--;
            }
            else{
                i++;
            }
        }
        return {-1, -1};
    }
};
// PROBLEM:- https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
