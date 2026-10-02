class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // make all nums to positive and sort them
        for(int i=0; i<nums.size(); i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());

        // calculate the answer such that from end we have to take number for addition and from start we have to take number for substration
        long long ans = 0;
        int i=0, j=nums.size()-1;
        bool flag = true;
        while(i <= j){
            if(flag){
                ans += pow(nums[j], 2);
                j--;
            }
            else{
                ans -= pow(nums[i], 2);
                i++;
            }
            flag = !flag;
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/maximum-alternating-sum-of-squares/description/
