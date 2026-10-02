class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> lossCount, winCount;
        for(vector<int> &match: matches){
            int winner = match[0];
            int losser = match[1];
            lossCount[losser]++;
            winCount[winner]++;
        }

        vector<vector<int>> ans(2, vector<int>());
        for(auto itr=winCount.begin(); itr!=winCount.end(); itr++){
            if(lossCount[itr->first] == 0){
                ans[0].push_back(itr->first);
            }
        }
        for(auto itr=lossCount.begin(); itr!=lossCount.end(); itr++){
            if(itr->second == 1){
                ans[1].push_back(itr->first);
            }
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/
