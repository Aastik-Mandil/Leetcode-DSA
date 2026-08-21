class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size() == 2){
            return nums;
        }

        long long ans = 0;
        for(int &num: nums){
            ans ^= num;
        }
        cout<<ans<<endl;

        int idx = 0;
        while(((ans >> idx) & 1) == 0){
            idx++;
        }

        int first = 0, second = 0;
        for(int &num: nums){
            if(((num>>idx) & 1) == 1){
                first ^= num;
            }
            else{
                second ^= num;
            }
        }
        return {first, second};
    }
};
// PROBLEM:- https://leetcode.com/problems/single-number-iii/description/
