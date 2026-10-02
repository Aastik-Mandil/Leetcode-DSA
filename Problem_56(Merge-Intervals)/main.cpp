class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        for(int i=n-1; i>=0; i--){
            if(i+1 < intervals.size() && intervals[i][1] >= intervals[i+1][0]){
                intervals[i][0] = min(intervals[i][0], intervals[i+1][0]);
                intervals[i][1] = max(intervals[i][1], intervals[i+1][1]);
                intervals.erase(intervals.begin()+i+1);
                i++;
            }
        }
        return intervals;
    }
};
// PROBLEM:- https://leetcode.com/problems/merge-intervals/description
