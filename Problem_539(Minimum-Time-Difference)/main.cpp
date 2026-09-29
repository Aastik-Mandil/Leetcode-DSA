class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // convert it into hour and minute integer
        vector<vector<int>> v;
        for(string &timePoint: timePoints){
            int hour = stoi(timePoint.substr(0, 2));
            int minute = stoi(timePoint.substr(3, 2));
            v.push_back({hour, minute});
        }

        // sort these time
        sort(v.begin(), v.end());
        v.push_back({v[0][0]+24, v[0][1]});

        // calculate the consecutive difference between time
        int ans = INT_MAX;
        for(int i=1; i<v.size(); i++){
            int currHour = v[i-1][0];
            int nextHour = v[i][0];
            int diffHour = nextHour-currHour;

            int currMin = v[i-1][1];
            int nextMin = v[i][1];
            int diffMin = nextMin-currMin;
            
            int total = (diffHour * 60) + diffMin;
            ans = min(ans, total);
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/minimum-time-difference/description/
