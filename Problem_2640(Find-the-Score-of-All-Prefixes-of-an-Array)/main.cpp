class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        long long maxi = 0, prev = 0;
        vector<long long> ans;
        for(int &num: nums){
            if(num > maxi){
                maxi = num;
            }
            long long total = maxi + num + prev;
            ans.push_back(total);
            prev = total;
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array/description/
