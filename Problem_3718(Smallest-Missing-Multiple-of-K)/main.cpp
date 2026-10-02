class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> v(101, 0);
        for(int &num: nums){
            v[num]++;
        }

        int last = -1;
        for(int i=k; i<=100; i+=k){
            if(v[i] == 0){
                return i;
            }
            last = i;
        }
        return last + k;
    }
};
// PROBLEM:- https://leetcode.com/problems/smallest-missing-multiple-of-k/description/
