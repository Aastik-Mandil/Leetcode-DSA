class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k != 0){
            return false;
        }

        map<int, int> mp;
        for(int &num: nums){
            mp[num]++;
        }

        while(mp.size() > 0){
            auto itr = mp.begin();
            int val = itr->first;
            for(int i=0; i<k; i++){
                if(mp[val+i] > 0){
                    mp[val+i]--;
                    if(mp[val+i] == 0){
                        mp.erase(val+i);
                    }
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
// PROBLEM:- https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/description/
