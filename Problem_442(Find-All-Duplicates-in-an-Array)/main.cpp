class Solution {
    vector<int> solveB(vector<int>& nums){
        vector<int> v(nums.size()+1, 0);
        vector<int> ans;
        for(int &num: nums){
            v[num]++;
            if(v[num] == 2){
                ans.push_back(num);
            }
        }
        return ans;
    }
    vector<int> solveO(vector<int> &nums){
        vector<int> ans;
        for(int &num: nums){
            if(nums[abs(num)-1] < 0){
                ans.push_back(abs(num));
            }
            nums[abs(num)-1] = 0 - nums[abs(num)-1];
        }
        return ans;
    }
public:
    vector<int> findDuplicates(vector<int> &nums) {
        // return solveB(nums);

        return solveO(nums);
    }
};
// PROBLEM:- https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
