class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int ans = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] + nums[j] == target){
                    ans++;
                }
                if(nums[j] + nums[i] == target){
                    ans++;
                }
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/description/
