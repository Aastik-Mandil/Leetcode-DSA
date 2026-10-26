class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // sort the pairs
        sort(pairs.begin(), pairs.end());

        // create the maxlen chain pair and find the maximum values
        int n = pairs.size();
        int ans = 0;
        vector<int> len(n, 1);
        for(int i=n-1; i>=0; i--){
            int idx = -1;
            for(int j=i+1; j<n; j++){
                if(pairs[i][1] < pairs[j][0]){
                    len[i] = max(len[i], 1 + len[j]);
                }
                else if(pairs[i][1] == pairs[j][0]){
                    len[i] = max(len[i], len[j]);
                }
            }
            ans = max(ans, len[i]);
        }

        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/maximum-length-of-pair-chain/description/
