class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int lastIdx = 0;
        for(int i=1; i<colors.size(); i++){
            if(colors[i] == colors[lastIdx]){
                if(neededTime[i] > neededTime[lastIdx]){
                    ans += neededTime[lastIdx];
                    lastIdx = i;
                }
                else{
                    ans += neededTime[i];
                }
            }
            else{
                lastIdx = i;
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/
