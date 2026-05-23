class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int n = asteroids.size();
        for(int i=0; i<n; i++){
            if(ans.size() == 0){
                ans.push_back(asteroids[i]);
            }
            else{
                if(asteroids[i] > 0){
                    ans.push_back(asteroids[i]);
                }
                else{
                    bool canInserted = true;
                    while(ans.size() > 0 && ans.back() > 0 && ans.back() < abs(asteroids[i])){
                        ans.pop_back();
                    }
                    if(ans.size() > 0 && ans.back() > 0 && ans.back() == abs(asteroids[i])){
                        ans.pop_back();
                        canInserted = false;
                    }
                    else if(ans.size() > 0 && ans.back() > abs(asteroids[i])){
                        canInserted = false;
                    }
                    if(canInserted){
                        ans.push_back(asteroids[i]);
                    }
                }
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/asteroid-collision/description
