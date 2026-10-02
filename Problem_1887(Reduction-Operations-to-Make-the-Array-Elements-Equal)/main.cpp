class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        priority_queue<int> pq;
        for(int &num: nums){
            mp[num]++;
            if(mp[num] == 1){
                pq.push(num);
            }
        }

        int ans = 0;
        while(pq.size() > 1){
            int largest = pq.top();
            pq.pop();
            ans += mp[largest];
            mp[pq.top()] += mp[largest];
            mp.erase(largest);
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/description/
