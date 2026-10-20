class Solution {
    int getDigitSum(int n){
        int res = 0;
        while(n>0){
            res += (n%10);
            n/=10;
        }
        return res;
    }
public:
    int maximumSum(vector<int>& nums) {
        // create a map which store 2 maximum value for each key
        unordered_map<int, vector<int>> mp; // {key: {maxi1, maxi2}}
        int ans = -1;
        for(int &num: nums){
            int key = getDigitSum(num);
            if(mp[key].size() == 0){
                mp[key] = {num};
            }
            else if(mp[key].size() == 1){
                if(mp[key][0] < num){
                    mp[key].insert(mp[key].begin(), num);
                }
                else{
                    mp[key].push_back(num);
                }
                ans = max(ans, mp[key][0]+mp[key][1]);
            }
            else{
                if(mp[key][0] < num){
                    mp[key][1] = mp[key][0];
                    mp[key][0] = num;
                }
                else if(mp[key][1] < num){
                    mp[key][1] = num;
                }
                ans = max(ans, mp[key][0]+mp[key][1]);
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/
