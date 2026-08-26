class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int &num: nums){
            mp[num]++;
        }
        unordered_map<int, vector<int>> temp;
        for(auto itr=mp.begin(); itr!=mp.end(); itr++){
            temp[itr->second].push_back(itr->first);
        }
        for(int &num: nums){
            int freq = mp[num];
            if(temp[freq].size() == 1){
                return num;
            }
        }
        return -1;
    }
};
// PROBLEM:- https://leetcode.com/problems/first-element-with-unique-frequency/description/
