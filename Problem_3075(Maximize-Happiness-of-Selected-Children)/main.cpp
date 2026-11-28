class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin(), happiness.end(), greater<int> ());

        long long ans = 0, count = 0;
        for(int i=0; i<n && i<k; i++){
            ans += happiness[i]-count < 0 ? 0 : happiness[i]-count;
            count++;
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/maximize-happiness-of-selected-children/description/
