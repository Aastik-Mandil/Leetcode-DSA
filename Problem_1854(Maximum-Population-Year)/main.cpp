class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> v(101, 0);
        for(vector<int> &log: logs){
            int birth = log[0] - 1950;
            int death = log[1] - 1950;
            v[birth]++;
            v[death]--;
        }

        for(int i=1; i<=100; i++){
            v[i] += v[i-1];
        }

        int maxi = 0;
        for(int i=1; i<=100; i++){
            if(v[maxi] < v[i]){
                maxi = i;
            }
        }
        return maxi + 1950;
    }
};
// PROBLEM:- https://leetcode.com/problems/maximum-population-year/description/
