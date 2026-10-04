class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int ans = 0;
        int maxi = INT_MIN;
        int n = weight.size();
        for(int i=0; i<n; i++){
            if(maxi == INT_MIN){
                maxi = weight[i];
            }
            else{
                if(weight[i] < maxi){
                    ans++;
                    maxi = INT_MIN;
                }
                else{
                    maxi = max(maxi, weight[i]);
                }
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/maximum-balanced-shipments/description/
