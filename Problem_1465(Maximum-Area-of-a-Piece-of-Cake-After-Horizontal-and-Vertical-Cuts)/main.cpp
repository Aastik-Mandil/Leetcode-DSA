int mod = 1e9 + 7;

class Solution {
public:
    int maxArea(int height, int width, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(height);
        sort(horizontalCuts.begin(), horizontalCuts.end());
 
        verticalCuts.push_back(0);
        verticalCuts.push_back(width);
        sort(verticalCuts.begin(), verticalCuts.end());

        long long maxWidth = 0;
        for(int i=1;i<horizontalCuts.size();i++){
            if((horizontalCuts[i] - horizontalCuts[i-1]) > maxWidth){
                maxWidth = (horizontalCuts[i] - horizontalCuts[i-1]);
            }
        }
        long long maxHeight = 0;
        for(int i=1;i<verticalCuts.size();i++){
            if((verticalCuts[i] - verticalCuts[i-1]) > maxHeight){
                maxHeight = (verticalCuts[i] - verticalCuts[i-1]);
            }
        }
        long long ans = maxWidth*maxHeight;

        return ans%mod;
    }
};
// PROBLEM:- https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/description/
