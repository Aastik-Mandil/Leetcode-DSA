class Solution {
public:
    int countElements(vector<int>& nums) {
        if(nums.size() < 2){
            return 0;
        }

        sort(nums.begin(), nums.end());
        int st = 0, ed = nums.size() - 1;
        for(int i=1; i<nums.size(); i++){
            st = i;
            if(nums[i] > nums[i-1]){
                break;
            }
        }
        for(int i=nums.size()-2; i>=0; i--){
            ed = i;
            if(nums[i] < nums[i+1]){
                break;
            }
        }

        if(st > ed){
            return 0;
        }
        return ed-st+1;
    }
};
// PROBLEM:- https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/description/
