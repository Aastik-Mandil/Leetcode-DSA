class Solution {
    int calculateTime(vector<int> &startTime, vector<int> &duration, int currTime){
        int ans = INT_MAX;
        int n = startTime.size();
        for(int i=0; i<n; i++){
            if(startTime[i] >= currTime){
                ans = min(ans, startTime[i] + duration[i]);
            }
            else{
                ans = min(ans, currTime + duration[i]);
            }
        }
        return ans;
    }
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int val1 = 0;
        val1 = calculateTime(landStartTime, landDuration, val1);
        val1 = calculateTime(waterStartTime, waterDuration, val1);
        int val2 = 0;
        val2 = calculateTime(waterStartTime, waterDuration, val2);
        val2 = calculateTime(landStartTime, landDuration, val2);
        return min(val1, val2);
    }
};
// PROBLEM:- https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/description/
