class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int total = 0;
        for(int &num: nums){
            if(num%2 == 0){
                total += num;
            }
        }
        vector<int> ans;
        for(vector<int> &query: queries){
            int val = query[0];
            int idx = query[1];
            if(idx < nums.size()){
                if(nums[idx]%2 == 0){
                    total -= nums[idx];
                }
                nums[idx] += val;
                if(nums[idx]%2 == 0){
                    total += nums[idx];
                }
            }
            ans.push_back(total);
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/sum-of-even-numbers-after-queries/description/
