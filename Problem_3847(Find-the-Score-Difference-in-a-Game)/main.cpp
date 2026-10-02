class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int first = 0, second = 0;
        bool flag = true;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2 != 0){
                flag = !flag;
            }
            if((i+1)%6 == 0){
                flag = !flag;
            }
            if(flag){
                first += nums[i];
            }
            else{
                second += nums[i];
            }
        }
        return first - second;
    }
};
// PROBLEM:- https://leetcode.com/problems/find-the-score-difference-in-a-game/description/
