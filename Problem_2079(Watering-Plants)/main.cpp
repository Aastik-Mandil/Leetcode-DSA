class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans = 0;
        int n = plants.size();
        int size = capacity;
        for(int i=0; i<n; i++){
            if(plants[i] > size){
                ans += (2*i);
                size = capacity;
            }
            ans++;
            size -= plants[i];
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/watering-plants/description/
