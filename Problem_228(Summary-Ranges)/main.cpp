class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0){
            return {};
        }
        vector<string> v;
        int i = 0, j = 1;
        while(j < nums.size()){
            if(nums[j] == nums[j-1]+1){
            }
            else{
                if(j-i == 1){
                    v.push_back(to_string(nums[i]));
                }
                else{
                    v.push_back(to_string(nums[i])+"->"+to_string(nums[j-1]));
                }
                i = j;
            }
            j++;
        }
        if(j-i == 1){
            v.push_back(to_string(nums[i]));
        }
        else{
            v.push_back(to_string(nums[i])+"->"+to_string(nums[j-1]));
        }
        return v;
    }
};
// PROBLEM:- https://leetcode.com/problems/summary-ranges/description
