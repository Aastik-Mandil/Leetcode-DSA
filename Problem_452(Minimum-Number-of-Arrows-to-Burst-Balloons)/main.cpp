class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        int ans = 1, n = points.size();
        int st = points[0][0], ed = points[0][1];
        for(int i=1; i<n; i++){
            if(points[i][0] <= ed){
                st = max(st, points[i][0]);
                ed = min(ed, points[i][1]);
            }
            else{
                ans++;
                st = points[i][0];
                ed = points[i][1];
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description
