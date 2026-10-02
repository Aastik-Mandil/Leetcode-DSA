class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            if(words[i] == target){
                int idx = abs(startIndex - i);
                ans=min(ans, min(idx, n-idx));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/description/
