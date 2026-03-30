class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxi=0,count=0;
        for(int i=0;i<k;i++){
            count+=cardPoints[i];
        }
        maxi=max(maxi,count);
        int j=cardPoints.size()-1;
        for(int i=1;i<=k;i++){
            count-=cardPoints[k-i];
            count+=cardPoints[cardPoints.size()-i];
            maxi=max(maxi,count);
        }
        return maxi;
    }
};
// PROBLEM:- https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
