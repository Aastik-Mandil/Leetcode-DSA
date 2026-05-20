class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> order(n,0);
        for(vector<int> &val: trust){
            int u = val[0]-1;
            int v = val[1]-1;
            order[u]++;
            order[v]--;
        }
        for(int i=0;i<n;i++){
            if(order[i] == (1-n)){
                return i+1;
            }
        }
        return -1;
    }
};
// PROBLEM:- https://leetcode.com/problems/find-the-town-judge/description/
