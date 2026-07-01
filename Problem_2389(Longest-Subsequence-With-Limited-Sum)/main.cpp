class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());

        vector<int> ans;
        for(int &query: queries){
            int l=0, r=0;
            int total = 0;
            int maxi = 0;
            while(r < nums.size()){
                total += nums[r];
                while(l <= r && total > query){
                    total -= nums[l];
                    l++;
                }
                maxi = max(maxi, r-l+1);
                r++;
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/longest-subsequence-with-limited-sum/description/
