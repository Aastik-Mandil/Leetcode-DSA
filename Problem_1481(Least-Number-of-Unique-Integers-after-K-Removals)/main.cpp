typedef pair<int, int> P;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // maintain the count of each number
        unordered_map<int, int> mp;
        for(int &num: arr){
            mp[num]++;
        }

        // store in such a way that leff count num will be on the top
        priority_queue<P, vector<P>, greater<P>> pq; // {count, num}
        for(auto itr=mp.begin(); itr!=mp.end(); itr++){
            pq.push({itr->second, itr->first});
        }

        // now remove the value if top val count is greater than equal to k else break the loop
        while(k > 0 && pq.size() > 0){
            int val = pq.top().first;
            if(k >= val){
                k -= val;
                pq.pop();
            }
            else{
                k = 0;
                break;
            }
        }
        // finally return the size of priority_queue
        return pq.size();
    }
};
// PROBLEM:- https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/
