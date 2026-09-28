class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        while(nums.size() > 0){
            // if odd num then reduce by 1
            for(int i=nums.size()-1; i>=0; i--){
                if(nums[i]%2 != 0){
                    nums[i]--;
                    ans++;
                }
                if(nums[i] == 0){
                    nums.erase(nums.begin()+i);
                }
            }
            if(nums.size() > 0){
                // if even num then divide by 2
                for(int i=nums.size()-1; i>=0; i--){
                    nums[i] /= 2;
                    if(nums[i] == 0){
                        nums.erase(nums.begin()+i);
                    }
                }
                ans++;
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/minimum-numbers-of-function-calls-to-make-target-array/description/
