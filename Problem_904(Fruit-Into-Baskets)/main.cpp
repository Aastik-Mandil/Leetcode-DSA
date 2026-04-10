class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0,r=0,k=2;
        unordered_map<int,int> mp;
        int ans=0;
        while(r<fruits.size()){
            mp[fruits[r]]++;
            while(mp.size()>k){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            if(mp.size()<=k){
                ans=max(ans,r-l+1);
            }
            r++;
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/fruit-into-baskets/
