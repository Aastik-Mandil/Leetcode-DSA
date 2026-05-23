class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> res;
        for(int i=0;i<nums.size();i++){
            int j=i+1,k=nums.size()-1;
            int total = 0 - nums[i];
            while(j<k){
                int val = nums[j] + nums[k];
                if(val == total){
                    res.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(val > total){
                    k--;
                }
                else{
                    j++;
                }
            }
        }

        vector<vector<int>> ans;
        for(auto itr=res.begin(); itr!=res.end(); itr++){
            ans.push_back(*itr);
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/3sum/description/
