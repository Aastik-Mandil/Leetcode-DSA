class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        // sort the list
        sort(nums.begin(), nums.end());

        // create the result of size 3 if the max and min difference within k value
        vector<vector<int>> ans;
        for(int i=0; i<nums.size(); i+=3){
            if(nums[i+2] - nums[i] > k){
                return {};
            }
            ans.push_back({nums[i], nums[i+1], nums[i+2]});
        }
        return ans;
    }
};
// PROBELM:- https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/
