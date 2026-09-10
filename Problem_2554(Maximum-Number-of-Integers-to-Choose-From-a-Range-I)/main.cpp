class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int, int> mp;
        for(int &num: banned){
            mp[num] = 1;
        }
        int total = 0, ans = 0;
        for(int i=1; (total+i)<=maxSum && i<=n; i++){
            if(mp[i] == 0){
                total += i;
                ans++;
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/description/
