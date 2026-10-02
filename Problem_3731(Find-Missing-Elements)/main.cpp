class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0];
        for(int &num: nums){
            maxi = max(maxi, num);
            mini = min(mini, num);
        }

        vector<int> v(maxi-mini+1, 0);
        for(int &num: nums){
            v[num-mini]++;
        }

        vector<int> ans;
        for(int i=0; i<v.size(); i++){
            if(v[i] == 0){
                ans.push_back(i+mini);
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/find-missing-elements/description/
