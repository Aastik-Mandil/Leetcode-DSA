class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> idx;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == x){
                idx.push_back(i);
            }
        }

        vector<int> ans;
        for(int &query: queries){
            if(query <= idx.size()){
                ans.push_back(idx[query-1]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/find-occurrences-of-an-element-in-an-array/description/
