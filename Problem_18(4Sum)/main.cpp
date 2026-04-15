class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long long tar = target;

        set<vector<int>> res;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int st=j+1,ed=n-1;
                long long total = tar - nums[i] - nums[j];
                while(st<ed){
                    if(nums[st]+nums[ed] == total){
                        res.insert({nums[i], nums[j], nums[st], nums[ed]});
                        st++;
                        ed--;
                    }
                    else if(nums[st]+nums[ed] > total){
                        ed--;
                    }
                    else{
                        st++;
                    }
                }
            }
        }

        vector<vector<int>> ans;
        for(auto itr=res.begin();itr!=res.end();itr++){
            ans.push_back(*itr);
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/4sum/description/
