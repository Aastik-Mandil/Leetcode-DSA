class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1;
        int ans = INT_MIN;
        while(i<j){
            int val = (j-i) * min(height[i], height[j]);
            ans = max(ans, val);
            if(height[j] >= height[i]){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/container-with-most-water/description/
