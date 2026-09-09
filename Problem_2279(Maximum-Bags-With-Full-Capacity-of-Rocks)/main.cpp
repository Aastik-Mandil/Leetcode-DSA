class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        // calculate the remaining capacity
        vector<int> rem(n);
        for(int i=0; i<n; i++){
            rem[i] = capacity[i] - rocks[i];
        }

        // sort them in the ascending order
        sort(rem.begin(), rem.end());

        // now add the additionalRocks in the sequencial order and check it if can fill the bag
        int ans = 0;
        for(int i=0; i<n && additionalRocks>0; i++){
            if(additionalRocks >= rem[i]){
                ans++;
                additionalRocks -= rem[i];
            }
            else{
                break;
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/description/
