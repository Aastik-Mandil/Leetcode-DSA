class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0, j = 0;
        int n = firstList.size(), m = secondList.size();
        vector<vector<int>> ans;
        while(i<n && j<m){
            if(secondList[j][0] > firstList[i][1]){
                i++;
            }
            else if(secondList[j][1] < firstList[i][0]){
                j++;
            }
            else{
                ans.push_back({
                    max(firstList[i][0], secondList[j][0]),
                    min(firstList[i][1], secondList[j][1])
                });
                if(secondList[j][1] > firstList[i][1]){
                    i++;
                }
                else{
                    j++;
                }
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/interval-list-intersections/description/
