class Solution {
    int ans = INT_MAX;
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            int st=i+1, ed=n-1;
            while(st<ed){
                int val = nums[st]+nums[ed]+nums[i];
                if(ans == INT_MAX || abs(target-val)<abs(target-ans)){
                    ans = val;
                }
                if(target == val){
                    ans = target;
                }
                if(target > val){
                    st++;
                }
                else{
                    ed--;
                }
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/3sum-closest/description/
