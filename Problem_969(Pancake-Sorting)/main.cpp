#include <algorithm>

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        while(n>1){
            auto itr = find(arr.begin(), arr.begin()+n, n);
            int idx = distance(arr.begin(), itr);
            if(idx != n){
                reverse(arr.begin(), arr.begin()+idx+1);
                if(idx != 0){
                    ans.push_back(idx+1);
                }
                ans.push_back(n);
                reverse(arr.begin(), arr.begin()+n);
            }
            n--;
        }
        return ans;
    }
};
// Example
// 3 2 4 1
// 4 2 3 1 -> 3
// 1 3 2 4 -> 4
// 3 1 2 4 -> 2
// 2 1 3 4 -> 3
// 1 2 3 4 -> 2
// PROBLEM:- https://leetcode.com/problems/pancake-sorting/description/
