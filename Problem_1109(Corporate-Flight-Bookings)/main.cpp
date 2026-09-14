class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);
        for(vector<int> &booking: bookings){
            int st = booking[0] - 1;
            int ed = booking[1] - 1;
            int val = booking[2];
            ans[st] += val;
            if(ed+1 < n){
                ans[ed+1] -= val;
            }
        }
        for(int i=1; i<n; i++){
            ans[i] += ans[i-1];
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/corporate-flight-bookings/description/
