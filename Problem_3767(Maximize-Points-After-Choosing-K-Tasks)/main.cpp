class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n = technique1.size();

        // calculate total points if all task do from technique 1
        long long ans = 0;
        for(int i=0; i<n; i++){
            ans += technique1[i];
        }

        // calculate difference if the task has to do from technique 2
        vector<int> v(n);
        for(int i=0; i<n; i++){
            v[i] = technique2[i] - technique1[i];
        }

        // sort in descending order
        sort(v.begin(), v.end(), greater<int>());

        // only do if it increase the points
        for(int i=0; i<(n-k); i++){
            if(v[i] > 0){
                ans += v[i];
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/maximize-points-after-choosing-k-tasks/description/
