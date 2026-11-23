class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<vector<int>> v; // {mappedValue, idx, num}
        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            string val = to_string(num);
            int total = 0;
            for(char &ch: val){
                total = (10*total) + mapping[ch-'0'];
            }
            v.push_back({total, i, nums[i]});
        }
        
        sort(v.begin(), v.end());

        vector<int> ans;
        for(vector<int> &temp: v){
            ans.push_back(temp[2]);
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/sort-the-jumbled-numbers/description/
