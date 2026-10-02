typedef pair<int,int> P;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int st = candidates, ed = costs.size() - candidates - 1;
        priority_queue<P, vector<P>, greater<P>> pq;
        if(costs.size() <= (2 * candidates)){
            for(int i=0; i<costs.size(); i++){
                pq.push({costs[i], i});
            }
        }
        else{
            for(int i=0; i<candidates; i++){
                pq.push({costs[i], i});
                pq.push({costs[costs.size()-1-i], costs.size()-1-i});
            }
        }

        long long ans = 0;
        while(k--){
            int cost = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            ans += cost;
            if(st <= ed){
                if(idx < st){
                    pq.push({costs[st], st});
                    st++;
                }
                else{
                    pq.push({costs[ed], ed});
                    ed--;
                }
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/total-cost-to-hire-k-workers/description
