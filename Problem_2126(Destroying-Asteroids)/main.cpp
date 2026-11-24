class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();

        // sorting the asteroids in asc
        sort(asteroids.begin(), asteroids.end());

        long long total = mass;
        for(int &asteroid: asteroids){
            if(total < asteroid){
                return false;
            }
            total += asteroid;
        }
        return true;
    }
};
// PROBLEM:- https://leetcode.com/problems/destroying-asteroids/description/
