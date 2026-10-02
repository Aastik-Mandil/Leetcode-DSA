class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> temp(101, 0);
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for(int i=n-1; i>=0; i--){
            temp[temperatures[i]] = i+1;
            int mini = INT_MAX;
            for(int st = temperatures[i]+1; st<=100; st++){
                if(temp[st]>0){
                    mini = min(mini,temp[st]-i-1);
                }
            }
            ans[i] = mini == INT_MAX ? 0 : mini;
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/daily-temperatures/description
