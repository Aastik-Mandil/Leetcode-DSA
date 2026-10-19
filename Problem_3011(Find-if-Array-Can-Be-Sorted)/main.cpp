class Solution {
    int countSetBit(int n){
        if(n == 0){
            return 0;
        }
        return 1 + countSetBit(n & (n-1));
    }
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        
        // calculate the set bits of all the number
        vector<int> bits(n, 0);
        for(int i=0; i<n; i++){
            bits[i] = countSetBit(nums[i]);
        }

        // find all same consecutive set bits and sort those group in the original nums list
        int last = 0;
        for(int idx=1; idx<n; idx++){
            if(bits[idx] != bits[last]){
                sort(nums.begin()+last, nums.begin()+idx);
                last = idx;
            }
        }
        sort(nums.begin()+last, nums.begin()+n);

        // finally check after the operation the whole list is sorted or not
        for(int i=1; i<n; i++){
            if(nums[i] < nums[i-1]){
                return false;
            }
        }
        return true;
    }
};
// PROBLEM:- https://leetcode.com/problems/find-if-array-can-be-sorted/description/
