class Solution {
    int solve(int k, int w, vector<int>& profits, vector<int>& capital){
        int n = profits.size();
        int currWeight = w;
        map<int, vector<int>> mp;

        // map: {cal -> {profit}}
        for(int i=0; i<n; i++){
            mp[capital[i]].push_back(profits[i]);
        }

        priority_queue<pair<int,int>> pq; // {profit, cap}
        auto itr = mp.begin();
        while(itr != mp.end() && itr->first <= currWeight){
            for(int &profit: mp[itr->first]){
                cout<<itr->first<<" "<<profit<<endl;
                pq.push({profit, itr->first});
            }
            itr++;
        }

        while(k > 0 && pq.size()>0){
            k--;
            currWeight += pq.top().first;
            pq.pop();
            while(itr != mp.end() && itr->first <= currWeight){
                for(int &profit: mp[itr->first]){
                    cout<<itr->first<<" "<<profit<<endl;
                    pq.push({profit, itr->first});
                }
                itr++;
            }
        }
        return currWeight;
    }
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        return solve(k, w, profits, capital);
    }
};
// PROBLEM:- https://leetcode.com/problems/ipo/description
