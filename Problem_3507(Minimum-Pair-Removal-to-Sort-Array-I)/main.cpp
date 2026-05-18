class Solution {
    bool isNotIncreaasing(vector<int> &nums){
        for(int i=1; i<nums.size(); i++){
            if(nums[i] < nums[i-1]){
                return true;
            }
        }
        return false;
    }
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;
        while(isNotIncreaasing(nums)){
            int idx = -1;
            int mini = INT_MAX;
            for(int i=0; i<(nums.size()-1); i++){
                if(nums[i]+nums[i+1] < mini){
                    mini = nums[i]+nums[i+1];
                    idx = i;
                }
            }
            if(idx != -1){
                count++;
                nums[idx] = mini;
                nums.erase(nums.begin()+idx+1);
            }
        }
        return count;
    }
};
// PROBLEM:- https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/description/
