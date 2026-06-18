class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end());

        int amount = 0;
        for(int &val: apple){
            amount += val;
        }

        int count = 0;
        int idx = capacity.size()-1;
        while(amount > 0 && idx >= 0){
            if(capacity[idx] <= amount){
                amount -= capacity[idx];
                idx--;
                count++;
            }
            else{
                count++;
                amount = 0;
                return count;
            }
        }
        return amount > 0 ? -1 : count;
    }
};
// PROBLEM:- https://leetcode.com/problems/apple-redistribution-into-boxes/description/
