class Solution {
    int shouldCount(vector<vector<int>>& points, int n, int a, int b){
        if(points[a][0] > points[b][0] && points[a][1] > points[b][1]){
            return 0;
        }
        if(points[a][0] < points[b][0] && points[a][1] < points[b][1]){
            return 0;
        }
        int minX = min(points[a][0], points[b][0]);
        int maxX = max(points[a][0], points[b][0]);
        int minY = min(points[a][1], points[b][1]);
        int maxY = max(points[a][1], points[b][1]);
        for(int i=0; i<n; i++){
            if(i == a || i == b){
                continue;
            }
            int x = points[i][0];
            int y = points[i][1];
            if(minX <= x && maxX >= x && minY <= y && maxY >= y){
                return 0;
            }
        }
        return 1;
    }
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ans += shouldCount(points, n, i, j);
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/description/
