class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> mp;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){}
            else if(bills[i]==10){
                if(mp[5]==0){
                    return false;
                }
                mp[5]--;
            }
            else{
                if(mp[5] == 0){
                    return false;
                }
                else if(mp[10] == 0){
                    if(mp[5] < 3){
                        return false;
                    }
                    mp[5]-=3;
                }
                else{
                    mp[10]--;
                    mp[5]--;
                }
            }
            mp[bills[i]]++;
        }
        return true;
    }
};
// PROBLEM:- https://leetcode.com/problems/lemonade-change/
