typedef pair<double, vector<int>> P;

class Solution {
    double getDistance(vector<int> &point){
        double ans = 0.00000;
        ans += (pow(point[0], 2) + pow(point[1], 2));
        return sqrt(ans);
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // store points in max-heap
        priority_queue<P, vector<P>> pq; // {dist, {x, y}}
        for(vector<int> &point: points){
            double dist = getDistance(point);
            pq.push({dist, point});
            if(pq.size() > k){
                pq.pop();
            }
        }

        // get alll points and store in list
        vector<vector<int>> ans;
        while(pq.size() > 0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
// PROBELM:- https://leetcode.com/problems/k-closest-points-to-origin/description/
