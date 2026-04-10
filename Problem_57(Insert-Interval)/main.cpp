class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        bool flag=false;
        for(int i=0;i<n;i++){
            if(newInterval[0]<intervals[i][1]){
                intervals.insert(intervals.begin()+i, newInterval);
                flag=true;
                break;
            }
        }
        if(!flag){
            if(n>0 && newInterval[0]<intervals[0][1]){
                intervals.insert(intervals.begin(), newInterval);
            }
            else{
                intervals.push_back(newInterval);
            }
        }

        int i=1;
        while(i<intervals.size()){
            if(intervals[i-1][1]>=intervals[i][0]){
                intervals[i-1][0]=min(intervals[i-1][0],intervals[i][0]);
                intervals[i-1][1]=max(intervals[i-1][1],intervals[i][1]);
                intervals.erase(intervals.begin()+i);
            }
            else{
                i++;
            }
        }
        return intervals;
    }
};
// PROBLEM:- https://leetcode.com/problems/insert-interval/
