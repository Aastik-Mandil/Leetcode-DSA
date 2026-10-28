class Solution {
public:
    int maxDistance(vector<int>& colors) {
        vector<int> v(101, -1);
        for(int i=0; i<colors.size(); i++){
            if(v[colors[i]] == -1){
                v[colors[i]] = i;
            }
        }
        for(int i=0; i<=100; i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;

        int mini = -1, maxi = -1;
        for(int i=0; i<=100; i++){
            if(v[i] != -1){
                if(mini == -1){
                    mini = v[i];
                }
                else{
                    mini = min(mini, v[i]);
                }
            }
            if(v[i] != -1){
                if(maxi == -1){
                    maxi = v[i];
                }
                else{
                    maxi = max(maxi, v[i]);
                }
            }
        }
        cout<<maxi<<" "<<mini<<endl;
        return maxi-mini;
    }
};
// PROBLEM:- https://leetcode.com/problems/two-furthest-houses-with-different-colors/description/
