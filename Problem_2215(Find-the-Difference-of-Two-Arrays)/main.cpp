class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1, mp2;
        for(int &num1: nums1){
            mp1[num1] = 1;
        }
        for(int &num2: nums2){
            mp2[num2] = 2;
        }

        vector<vector<int>> ans(2);
        for(auto itr=mp1.begin(); itr!=mp1.end(); itr++){
            if(mp2[itr->first] != 2){
                ans[0].push_back(itr->first);
            }
        }
        for(auto itr=mp2.begin(); itr!=mp2.end(); itr++){
            if(mp1[itr->first] != 1){
                ans[1].push_back(itr->first);
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/find-the-difference-of-two-arrays/description
