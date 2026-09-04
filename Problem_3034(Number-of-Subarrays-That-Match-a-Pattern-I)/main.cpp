class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int ans = 0;
        for(int i=0; i<(nums.size()-pattern.size()); i++){
            bool flag = true;
            for(int k=0; k<pattern.size(); k++){
                if(pattern[k] == 1 && nums[i+k] < nums[i+k+1]){}
                else if(pattern[k] == 0 && nums[i+k] == nums[i+k+1]){}
                else if(pattern[k] == -1 && nums[i+k] > nums[i+k+1]){}
                else{
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans++;
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/number-of-subarrays-that-match-a-pattern-i/description/
