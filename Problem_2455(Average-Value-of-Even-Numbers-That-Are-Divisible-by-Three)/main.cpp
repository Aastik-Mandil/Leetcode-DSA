class Solution {
public:
    int averageValue(vector<int>& nums) {
        int total = 0, count = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%6 == 0){
                total += nums[i];
                count++;
            }
        }
        if(count == 0){
            return 0;
        }
        return total/count;
    }
};
// PROBLEM:- https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three/description/
