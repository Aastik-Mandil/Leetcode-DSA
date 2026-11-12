typedef pair<int, char> P;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // sort based on starting of the interval
        sort(intervals.begin(), intervals.end());

        // create a min-heap
        priority_queue<int, vector<int>, greater<int>> pq; // {endInterval}
        int ans = 0;
        for(vector<int> &interval: intervals){
            // remove all the intervals which has less endTime from current interval start time
            while(pq.size() > 0 && pq.top() < interval[0]){
                pq.pop();
            }
            pq.push(interval[1]);
            if(ans < pq.size()){
                ans = pq.size();
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/
