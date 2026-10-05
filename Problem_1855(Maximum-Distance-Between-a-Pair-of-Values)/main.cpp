class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int i = 0, j = 0;
        while(i<nums1.size() && j<nums2.size()){
            while(i<nums1.size() && j<nums2.size() && i <= j && nums1[i] <= nums2[j]){
                j++;
            }
            if(j-1>=0 && i <= (j-1) && nums1[i] <= nums2[j-1]){
                ans = max(ans, j-1-i);
            }
            i++;
            if(i > j){
                j = i;
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/description/
