class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        if(n==0){
            return {};
        }
        for(int i=0;i<n;i++){
            tasks[i].push_back(i);
        }

        sort(tasks.begin(),tasks.end());
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // {dur, id}
        int i=0;
        
        vector<int> ans;
        while(i<n){
            long long curr=tasks[i][0];
            pq.push({tasks[i][1], tasks[i][2]});
            i++;
            while(pq.size()>0){
                int duration=pq.top().first;
                curr+=duration;
                int idx=pq.top().second;
                pq.pop();

                ans.push_back(idx);

                while(i<n && tasks[i][0]<=curr){
                    pq.push({tasks[i][1], tasks[i][2]});
                    i++;
                }
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/single-threaded-cpu/
