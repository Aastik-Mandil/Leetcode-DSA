double mod = 1e9 + 7;

class Solution {
    double getM(vector<int> p1, vector<int> p2){
        int x1 = p1[0], y1 = p1[1];
        int x2 = p2[0], y2 = p2[1];
        if(x1 == x2){
            return mod;
        }
        return ((y2-y1)*1.0) / ((x2-x1)*1.0);
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        vector<unordered_map<double, int>> mp(n);
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(i == j){
                    continue;
                }
                double m = getM(points[i], points[j]);
                mp[i][m]++;
                cnt = max(cnt, mp[i][m]);
            }
            ans = max(ans, cnt+1);
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/max-points-on-a-line/description
