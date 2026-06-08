class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = INT_MAX;
        vector<vector<int>> v(101, vector<int>());
        for(int i=0; i<nums.size(); i++){
            v[nums[i]].push_back(i);
            int n = v[nums[i]].size();
            vector<int> z = v[nums[i]];
            if(n >= 3){
                int i = z[n-3];
                int j = z[n-2];
                int k = z[n-1];
                ans = min(ans, abs(i-j) + abs(j-k) + abs(k-i));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
// PROBLEM:-https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/description/
