class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int>& nums) {
        vector<int> seen;
        vector<int> ans;
        int count = 0;
        for(int &num: nums){
            if(num == -1){
                count++;
                if(seen.size() >= count){
                    ans.push_back(seen[count-1]);
                }
                else{
                    ans.push_back(-1);
                }
            }
            else{
                seen.insert(seen.begin(), num);
                count = 0;
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/last-visited-integers/description/
