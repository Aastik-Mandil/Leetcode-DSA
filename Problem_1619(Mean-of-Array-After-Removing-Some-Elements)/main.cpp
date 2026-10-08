class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int removingCount = arr.size() * 0.05;
        int l = removingCount, r = arr.size() - removingCount;
        double val = 0.00000, count = 0.00000;
        for(int i=l; i<r; i++){
            val += arr[i];
            count++;
        }
        double ans = (val * 1.00000) / (count * 1.00000);
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/mean-of-array-after-removing-some-elements/description/
