class Solution {
    vector<vector<int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    
    bool canPick(int n, int m, int x, int y){
        return x>=0 && y>=0 && x<n && y<m;
    }
    int getAvg(vector<vector<int>>& img, int n, int m, int x, int y){
        int total = 0, count = 0;
        for(vector<int> &dir: dirs){
            int newX = x + dir[0];
            int newY = y + dir[1];
            if(canPick(n, m, newX, newY)){
                total += img[newX][newY];
                count++;
            }
        }
        return total / count;
    }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans[i][j] = getAvg(img, n, m, i, j);
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/image-smoother/description/
