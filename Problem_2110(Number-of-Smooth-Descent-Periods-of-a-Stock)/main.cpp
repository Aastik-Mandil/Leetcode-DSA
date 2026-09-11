class Solution {

public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long ans = 0, count = 1;
        for(int i=1; i<n; i++){
            if(prices[i]+1 == prices[i-1]){
                count++;
            }
            else{
                ans += ((count * (count+1)) / 2);
                count = 1;
            }
        }
        ans += ((count * (count+1)) / 2);
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/description/
