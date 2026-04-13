class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int total = nums.size();
        k%=total;
        vector<int> temp;
        for(int i=nums.size()-k;i<nums.size();i++){
            temp.push_back(nums[i]);
        }

        for(int i=nums.size()-k-1;i>=0;i--){
            nums[i+k] = nums[i];
        }
        for(int i=0;i<temp.size();i++){
            nums[i] = temp[i];
        }
    }
};
// PROBLEM:- https://leetcode.com/problems/rotate-array/description/
