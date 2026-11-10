class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        map<int, int> mp;
        for(vector<int> &point: points){
            int x = point[0];
            mp[x]++;
        }

        int last = -1, ans = 0;
        for(auto itr=mp.begin(); itr!=mp.end(); itr++){
            if(itr->first > last){
                ans++;
                last = itr->first + w;
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/minimum-rectangles-to-cover-points/description/
