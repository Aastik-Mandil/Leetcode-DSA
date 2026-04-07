
class Solution {
    int ans=INT_MAX;
    int findMaximum(vector<int> &bags){
        int res = 0;
        for(int val: bags){
            res=max(res, val);
        }
        return res;
    }
    void distributionR(vector<int> &cookies, int ind, vector<int> &bags){
        if(ind==0){
            int maxi = findMaximum(bags);
            ans=min(ans,maxi);
            return;
        }
        for(int i=0;i<bags.size();i++){
            bags[i]+=cookies[ind-1];
            distributionR(cookies, ind-1, bags);
            bags[i]-=cookies[ind-1];
        }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> bags(k,0);
        distributionR(cookies,cookies.size(),bags);
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/fair-distribution-of-cookies/description/
