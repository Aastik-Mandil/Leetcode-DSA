class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int curr = 0;
        double ans = 0.00000;
        for(vector<int> &customer: customers){
            int arrival = customer[0];
            int time = customer[1];
            if(curr >= arrival){
                curr += time;
            }
            else{
                curr = arrival+time;
            }
            ans += ((curr - arrival) * 1.00000);
        }

        return ans/customers.size();
    }
};
// PROBLEM:- https://leetcode.com/problems/average-waiting-time/description/
